//gcc -fopenmp -O3 -march=native studentspar.c -o studentspar -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

#define NRO_COLUNAS_TABELAS_NOTAS 5
#define NRO_COLUNAS_TABELA_PREMIACAO 2

#define COLUNA_MIN 0
#define COLUNA_MAX 1
#define COLUNA_MEDIANA 2
#define COLUNA_MEDIA 3
#define COLUNA_DESVIO 4

//Variável global do tamanho da linha de cache
//Seu valor é definido no main()
long QTD_BYTES_LINHA;

//Para facilitar a organização
typedef struct
{
    //tamanhoBlocos = quantidade de dados por linha, com padding
    //Ou seja, nroColuans = quantidade de dados úteis, tamanhoBlocos = quantidade de dados com padding
    //Importante pra evitar false sharing
    int nroLinhas, nroColunas, tamanhoBlocos;
    float *tabela;
} TabelasDados;

//Para evitar false sharing
//Calcula quantos floats devem existir em cada bloco para ocupar linhas inteiras
int TamanhoBlocoPreencherLinha(int nroColunas, int tamanhoDado)
{
    int dadosPorLinha = (QTD_BYTES_LINHA/tamanhoDado);

    //(x + y - 1)/y é uma forma de arredondar para cima
    //(15 + 16 - 1 = 30 -> 30/16 = 1.875 = 1) -> 15 floats ocupam 1 linha
    //(18 + 16 - 1 = 33 -> 33/16 = 2.0625 = 2) -> 18 floats ocupam 2 linhas
    return (int)((nroColunas + dadosPorLinha - 1)/dadosPorLinha) * dadosPorLinha;
}

void ImprimirTabela(TabelasDados tabela)
{
    for (int i = 0; i < tabela.nroLinhas; ++i)
    {
        for (int j = 0; j < tabela.nroColunas; ++j)
        {
            printf("%.1f ", tabela.tabela[i*tabela.tamanhoBlocos + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void LiberarTabela(TabelasDados tabela)
{
    free(tabela.tabela);
}

//Ordena em ordem crescente
//Função de auxílio pro qsort
int FuncaoComparacao(const void *nota1, const void *nota2)
{
    float x = *(const float*)nota1;
    float y = *(const float*)nota2;
    return (x > y) - (x < y);
}

void OrdenarArray(float* array, int nroItens)
{
    //Função de ordenação do stdlib.h
    //Usa quicksort
    qsort(array, nroItens, sizeof(*array), FuncaoComparacao);
}

//Função auxiliar para facilitar a leitura do CombinarBlocos
void AvaliarPosicaoMerge(int *pos, const int tam, int *offset)
{
    (*pos)++;
    if (*pos >= tam)
    {
        (*pos) = 0;
        (*offset)++;
    }
}

//Função que combina dois blocos do merge sort em ordem crescente
//tam1 e tam2 são a quantidade de blocos de floats dentro de cada bloco do merge
//qtdValores é a quantidade de floats dentro de cada bloco de float
//tamanhoBlocos é o tamanho de cada bloco de float, incluindo o padding
void CombinarBlocos(float* dados, const int tam1, const int tam2, const int offset1, const int offset2, 
                        float* saida, const int qtdValores, const int tamanhoBlocos)
{
    int i = 0, j = 0, k = 0;
    int offsetAtual1 = offset1, offsetAtual2 = offset2, offsetAtualSaida = offset1;
    int dadosTotais1 = 0, dadosTotais2 = 0;

    int valoresBlocos1 = tam1 * qtdValores, valoresBlocos2 = tam2 * qtdValores;

    //Ordena até que um dos blocos do merge termine
    while (dadosTotais1 < valoresBlocos1 && dadosTotais2 < valoresBlocos2)
    {
        if (dados[offsetAtual1*tamanhoBlocos + i] < dados[offsetAtual2*tamanhoBlocos + j])
        {
            saida[offsetAtualSaida*tamanhoBlocos + k] = dados[offsetAtual1*tamanhoBlocos + i];
            AvaliarPosicaoMerge(&i, qtdValores, &offsetAtual1);
            dadosTotais1++;
        }
        else
        {
            saida[offsetAtualSaida*tamanhoBlocos + k] = dados[offsetAtual2*tamanhoBlocos + j];
            AvaliarPosicaoMerge(&j, qtdValores, &offsetAtual2);
            dadosTotais2++;
        }
        AvaliarPosicaoMerge(&k, qtdValores, &offsetAtualSaida);
    }

    //Coloca o restante do bloco do merge incompleto no final, pois todos os valores são maiores e já ordenados

    while (dadosTotais1 < valoresBlocos1)
    {
        saida[offsetAtualSaida*tamanhoBlocos + k] = dados[offsetAtual1*tamanhoBlocos + i];
        AvaliarPosicaoMerge(&i, qtdValores, &offsetAtual1);
        AvaliarPosicaoMerge(&k, qtdValores, &offsetAtualSaida);
        dadosTotais1++;
    }
    while (dadosTotais2 < valoresBlocos2)
    {
        saida[offsetAtualSaida*tamanhoBlocos + k] = dados[offsetAtual2*tamanhoBlocos + j];
        AvaliarPosicaoMerge(&j, qtdValores, &offsetAtual2);
        AvaliarPosicaoMerge(&k, qtdValores, &offsetAtualSaida);
        dadosTotais2++;
    }
}

//Um merge sort que opera em blocos de tamanhos idênticos
//Extremamente útil para ordenar as regiões e o Brasil, pois é muito mais rápido que o quicksort
//qtdValores = quantidade de valores por bloco
//tamanhoBloco = tamanho dos blocos originais, que já possuem padding
void MergeSortBlocos(float *blocos, int qtdValores, int nroBlocos, int tamanhoBloco, float *saida)
{
    //Definição para auxiliar a leitura dos comentários:
    //Bloco do merge = blocos ordenados que são iterados, possuem 1 (na primeira iteração) ou mais blocos de float
    //Bloco de float = blocos internos aos blocos do merge, são os conjuntos de dados

    //Número de blocos do merge
    int nroBlocosAtuais = nroBlocos;

    float *blocosAtuais = aligned_alloc(QTD_BYTES_LINHA, nroBlocos * tamanhoBloco * sizeof(float));
    float *juncoes = aligned_alloc(QTD_BYTES_LINHA, nroBlocos * tamanhoBloco * sizeof(float));
    
    //Tamanhos dos blocos do merge (quantos blocos de float)
    int *tamanhosAtuais = malloc(nroBlocos * sizeof(int));

    //Quantos blocos de distância da origem
    int *offsets = malloc(nroBlocos * sizeof(int));

    //Copia todos os dados
    for (int i = 0; i < nroBlocos; ++i)
    {
        //Entre o final do bloco de float e o final da linha ficará padding
        memcpy(blocosAtuais + i*tamanhoBloco, blocos + i*tamanhoBloco, qtdValores * sizeof(float));
        tamanhosAtuais[i] = 1;
        offsets[i] = i;
    }

    //Enquanto tiverem blocos do merge para ordenar
    while (nroBlocosAtuais > 1)
    {
        //guided pois os blocos do merge podem ter tamanhos diferentes
        //nroBlocosAtuais/2 -> arredonda para baixo, então descondidera o último se nroBlocosAtuais for ímpar
        #pragma omp parallel for schedule(guided)
        for (int i = 0; i < nroBlocosAtuais/2; ++i)
        {
            //idx = indíce do bloco do merge
            int idx = 2 * i;
            //Offset do bloco do merge atual em termos de blocos de floats
            int offset1 = offsets[idx];
            int offset2 = offsets[idx + 1];
            //Quantidade de blocos de float no bloco de merge
            int tam1 = tamanhosAtuais[idx];
            int tam2 = tamanhosAtuais[idx + 1];

            //Combina os dois blocos de merge
            CombinarBlocos(blocosAtuais, tam1, tam2, offset1, offset2, juncoes, qtdValores, tamanhoBloco);

            //Copia os blocos ordenados para blocosAtuais
            for (int j = offset1; j < offset2 + tam2; ++j)
            {
                memcpy(blocosAtuais + j*tamanhoBloco, juncoes + j*tamanhoBloco, qtdValores * sizeof(float));
            }
        }

        //Ajusta os tamanhos e offsets dos blocos de merge
        for (int i = 0; i < nroBlocosAtuais/2; ++i)
        {
            tamanhosAtuais[i] = tamanhosAtuais[i * 2] + tamanhosAtuais[i * 2 + 1];
            offsets[i] = offsets[i*2];
        }
        //Se tinha um número ímpar, então o último não foi analisado
        if (nroBlocosAtuais % 2 == 1)
        {
            //Ajusta as informações nas listas auxiliares
            tamanhosAtuais[nroBlocosAtuais/2] = tamanhosAtuais[nroBlocosAtuais-1];
            offsets[nroBlocosAtuais/2] = offsets[nroBlocosAtuais-1];
        }

        //Mesmo princípio do tamanhoLinha: arredondar pra cima
        nroBlocosAtuais = (nroBlocosAtuais + 1) / 2;
    }

    //Copia todos os blocos de merge para a saída
    for (int i = 0; i < nroBlocos; ++i)
    {
        //Como o vetor de saída é um único bloco, avança em termos de i*qtdValores ao invés de tamanhoBloco
        memcpy(saida + i*qtdValores, blocosAtuais + i*tamanhoBloco, qtdValores * sizeof(float));
    }
    free(blocosAtuais);
    free(juncoes);
    free(tamanhosAtuais);
    free(offsets);
}

//Restrict -> nenhum outro local tem acesso ao mesmo ponteiro
//Então o compilador pode otimizar mais
float MediaDoVetor(float* restrict array, int nroItens)
{
    float media = 0;

    //Instrui que pode usar operações de simd
    #pragma omp simd reduction(+:media)
    for(int i = 0; i < nroItens; ++i)
    {
        media += array[i];
    }

    return media/nroItens;
}

//Restrict -> nenhum outro local tem acesso ao mesmo ponteiro
//Então o compilador pode otimizar mais
float MedianaDoVetor(float* restrict array, int nroItens)
{
    //Número ímpar de itens, então a mediana é o central
    if (nroItens % 2 == 1)
    {
        //(int) arredonda para baixo
        //Como a contagem começa em 0, então é a mediana exata
        return array[(int)nroItens/2];
    }
    //Número par de itens, então a mediana é a média dos 2 ao redor do meio
    else
    {
        float aux = 0.0;
        //Como a contagem começa em 0, então pega o abaixo da metade e a metade
        aux += array[nroItens/2 - 1];
        aux += array[nroItens/2];
        return aux/2.0;
    }
}

//Restrict -> nenhum outro local tem acesso ao mesmo ponteiro
//Então o compilador pode otimizar mais
float DesvioPadraoDoVetor(float* restrict array, int nroItens, float media)
{
    float soma = 0, aux;

    //Instrui que pode usar operações de simd
    #pragma omp simd reduction(+:soma) private(aux)
    for (int i = 0; i < nroItens; i++) {
        aux = array[i] - media;
        soma += aux * aux;
    }

    return sqrt(soma / nroItens);
}

int MontarTabelaImpressao(TabelasDados *destino, TabelasDados dados, int deveProcurarMax)
{
    //Retorna -1 para deixar explícito que não foi procurado
    int max = -1;
    //Se estiver procurando, define como 0 para não dar erro na análise abaixo
    if (deveProcurarMax == TRUE)
        max = 0;

    for (int i = 0; i < destino->nroLinhas; ++i)
    {
        //Como a tabela está ordenada, o mínimo é o primeiro e o máximo é o último
        int blocoAtualDestino = i*destino->tamanhoBlocos;
        int blocoAtualDados = i*dados.tamanhoBlocos;
        destino->tabela[blocoAtualDestino + COLUNA_MIN] = dados.tabela[blocoAtualDados + 0];
        destino->tabela[blocoAtualDestino + COLUNA_MAX] = dados.tabela[blocoAtualDados + dados.nroColunas-1];
        destino->tabela[blocoAtualDestino + COLUNA_MEDIANA] = MedianaDoVetor(dados.tabela + blocoAtualDados, dados.nroColunas);
        float media = MediaDoVetor(dados.tabela + blocoAtualDados, dados.nroColunas);
        destino->tabela[blocoAtualDestino + COLUNA_MEDIA] = media;
        destino->tabela[blocoAtualDestino + COLUNA_DESVIO] = 
                        DesvioPadraoDoVetor(dados.tabela + blocoAtualDados, dados.nroColunas, media);

        if (deveProcurarMax == TRUE)
        {
            if (destino->tabela[blocoAtualDestino + COLUNA_MAX] > destino->tabela[max + COLUNA_MAX])
                max = blocoAtualDestino;
        }
    }

    //Retorna o indíce do valor máximo encontrado
    return max/destino->tamanhoBlocos;
}

void GerarNotas(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, TabelasDados *notasAlunos)
{
    //nroRegioes * nroCidades * nroAlunos = (regiao, cidade, aluno)
    notasAlunos->nroLinhas = nroRegioes * nroCidades * nroAlunos;
    notasAlunos->nroColunas = nroNotas;
    //Como esta tabela terá paralelismo apenas quando estiver sendo lida, não há necessidade de lidar com false sharing
    notasAlunos->tamanhoBlocos = notasAlunos->nroColunas;
    notasAlunos->tabela = malloc(notasAlunos->nroLinhas * notasAlunos->tamanhoBlocos * sizeof(float));

    for (int i = 0; i < notasAlunos->nroLinhas; ++i)
    {
        for (int j = 0; j < nroNotas; ++j)
        {
            //rand()/RAND_MAX = float entre 0.0 e 1.0
            notasAlunos->tabela[i*notasAlunos->tamanhoBlocos + j] = (float)rand() / (float)RAND_MAX * 100;
        }
    }
}

void CalcularMediasPorCidade(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, 
                        TabelasDados notasAlunos, TabelasDados *mediasAlunosCidade)
{
    mediasAlunosCidade->nroLinhas = nroRegioes * nroCidades;
    mediasAlunosCidade->nroColunas = nroAlunos;
    mediasAlunosCidade->tamanhoBlocos = TamanhoBlocoPreencherLinha(mediasAlunosCidade->nroColunas, sizeof(float));
    //Para evitar false sharing
    //aligned_alloc -> garante que a memória irá ser criada no começo de uma linha de memória
    //Isto garante que os blocos não cruzarão as linhas, que criaria o false sharing
    mediasAlunosCidade->tabela = aligned_alloc(
                        QTD_BYTES_LINHA, mediasAlunosCidade->nroLinhas * mediasAlunosCidade->tamanhoBlocos * sizeof(float));

    //collapse(2) para garantir granularidade suficiente
    //Se nroLinhas for menor que nroThreads, teria um desperdício de processamento, o collapse resolve isso
    #pragma omp parallel for schedule(static) collapse(2)
    for (int i = 0; i < mediasAlunosCidade->nroLinhas; ++i)
    {
        for (int j = 0; j < mediasAlunosCidade->nroColunas; ++j)
        {
            mediasAlunosCidade->tabela[i*mediasAlunosCidade->tamanhoBlocos + j] = 
                            MediaDoVetor(notasAlunos.tabela + (i*nroAlunos + j)*notasAlunos.tamanhoBlocos, nroNotas);
        }
    }
}

void GerarTabelas(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, TabelasDados mediasAlunosCidade, 
                    TabelasDados *notasPorCidade, TabelasDados *notasPorRegiao, 
                    TabelasDados *notasBrasil, TabelasDados *notasPremiacao)
{
    //============== Este primeiro trecho separa os dados para cada análise ============== 

    //Tabelas auxiliares
    TabelasDados mediasPorRegiao, mediasBrasil;
    
    mediasPorRegiao.nroLinhas = nroRegioes;
    mediasPorRegiao.nroColunas = nroCidades * nroAlunos;
    mediasPorRegiao.tamanhoBlocos = TamanhoBlocoPreencherLinha(mediasPorRegiao.nroColunas, sizeof(float));;
    mediasPorRegiao.tabela = aligned_alloc(QTD_BYTES_LINHA,
                                            mediasPorRegiao.nroLinhas * mediasPorRegiao.tamanhoBlocos * sizeof(float));

    mediasBrasil.nroLinhas = 1;
    mediasBrasil.nroColunas = nroRegioes * nroCidades * nroAlunos;
    mediasBrasil.tamanhoBlocos = TamanhoBlocoPreencherLinha(mediasBrasil.nroColunas, sizeof(float));
    mediasBrasil.tabela = aligned_alloc(QTD_BYTES_LINHA, mediasBrasil.nroLinhas * mediasBrasil.tamanhoBlocos * sizeof(float));

    //============== Esta seção copia os dados para as outras tabelas e as ordena ==============
    
    #pragma omp parallel
    {
        //Ordena os blocos das cidades
        //Isso vai ser útil para ordenar os restantes, pois permite usar um merge sort adaptado, 
        //que é mais otimizado que o quicksort
        #pragma omp for schedule(static)
        for (int i = 0; i < nroRegioes * nroCidades; ++i)
        {
            OrdenarArray(mediasAlunosCidade.tabela + i * mediasAlunosCidade.tamanhoBlocos, mediasAlunosCidade.nroColunas);
        }

        //Com as cidades ordenadas, dá pra usar um merge sort nas regiões
        //O merge neste caso está programado para lidar exatamente com os blocos da cidade,
        //então é o mais otimizado possível

        #pragma omp for schedule(static)
        for (int i = 0; i < nroRegioes; i++)
        {
            MergeSortBlocos(mediasAlunosCidade.tabela + (i * nroCidades) * mediasAlunosCidade.tamanhoBlocos, 
                            nroAlunos, nroCidades, 
                            mediasAlunosCidade.tamanhoBlocos, mediasPorRegiao.tabela + i * mediasPorRegiao.tamanhoBlocos);
        }
    }

    //Com as regiões ordenadas, dá pra usar um merge sort no Brasil

    MergeSortBlocos(mediasPorRegiao.tabela, nroCidades * nroAlunos, nroRegioes, 
                        mediasPorRegiao.tamanhoBlocos, mediasBrasil.tabela);

    //============== Este trecho instancia as tabelas ============== 
    //Como nenhuma delas terá paralelização, não há necessidade de considerar false sharing

    notasPorCidade->nroLinhas = mediasAlunosCidade.nroLinhas;
    notasPorCidade->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasPorCidade->tamanhoBlocos = notasPorCidade->nroColunas;
    notasPorCidade->tabela = malloc(notasPorCidade->nroLinhas * notasPorCidade->tamanhoBlocos * sizeof(float));

    notasPorRegiao->nroLinhas = mediasPorRegiao.nroLinhas;
    notasPorRegiao->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasPorRegiao->tamanhoBlocos = notasPorRegiao->nroColunas;
    notasPorRegiao->tabela = malloc(notasPorRegiao->nroLinhas * notasPorRegiao->tamanhoBlocos * sizeof(float));

    notasBrasil->nroLinhas = mediasBrasil.nroLinhas;
    notasBrasil->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasBrasil->tamanhoBlocos = notasBrasil->nroColunas;
    notasBrasil->tabela = malloc(notasBrasil->nroLinhas * notasBrasil->tamanhoBlocos * sizeof(float));

    //Linha da região e linha da cidade
    notasPremiacao->nroLinhas = 2;
    notasPremiacao->nroColunas = NRO_COLUNAS_TABELA_PREMIACAO;
    notasPremiacao->tamanhoBlocos = notasPremiacao->nroColunas;
    notasPremiacao->tabela = malloc(notasPremiacao->nroLinhas * notasPremiacao->tamanhoBlocos * sizeof(float));

    //============== Este trecho organiza as tabelas ==============
    //Este trecho do código é tão leve que paralelizá-lo ia aumentar o tempo por overhead

    int melhorRegiao = 0, melhorCidade = 0;

    melhorCidade = MontarTabelaImpressao(notasPorCidade, mediasAlunosCidade, TRUE);
    melhorRegiao = MontarTabelaImpressao(notasPorRegiao, mediasPorRegiao, TRUE);
    MontarTabelaImpressao(notasBrasil, mediasBrasil, FALSE);
    
    notasPremiacao->tabela[0 * notasPremiacao->tamanhoBlocos + 0] = melhorRegiao;
    notasPremiacao->tabela[0 * notasPremiacao->tamanhoBlocos + 1] =
        notasPorRegiao->tabela[melhorRegiao * notasPorRegiao->tamanhoBlocos + COLUNA_MAX];

    notasPremiacao->tabela[1 * notasPremiacao->tamanhoBlocos + 0] = melhorCidade;
    notasPremiacao->tabela[1 * notasPremiacao->tamanhoBlocos + 1] =
        notasPorCidade->tabela[melhorCidade * notasPorCidade->tamanhoBlocos + COLUNA_MAX];

    //============== Este trecho libera as tabelas auxiliares ==============

    LiberarTabela(mediasBrasil);
    LiberarTabela(mediasPorRegiao);
}

int main()
{
    double tempoInicio, tempoFim;
    int nroRegioes, nroCidades, nroAlunos, nroNotas, limiteThreads, seed;
    TabelasDados notasAlunos, mediasAlunosCidade, notasPorCidade, notasPorRegiao, notasBrasil, notasPremiacao;

    scanf("%d %d %d %d %d %d", &nroRegioes, &nroCidades, &nroAlunos, &nroNotas, &limiteThreads, &seed);

    srand(seed);
    //Garante que não terá aninhamento de threads
    omp_set_nested(0);
    //omp_set_num_threads(limiteThreads);

    QTD_BYTES_LINHA = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    // Fallback de segurança caso o sistema não consiga informar
    if (QTD_BYTES_LINHA <= 0) {
        QTD_BYTES_LINHA = 64; 
    }

    printf("Tamanho da linha de cache do L1: %ld\n", QTD_BYTES_LINHA);

    double tempoInicioGerar = omp_get_wtime();
    GerarNotas(nroRegioes, nroCidades, nroAlunos, nroNotas, &notasAlunos);
    double tempoFimGerar = omp_get_wtime();
    printf("Geracao: %f\n", tempoFimGerar - tempoInicioGerar);

    //Início da seção paralelizável

    int w[4] = {1, 4, 8, 16};

    for (int j = 0; j < 4; j++)
    {
        omp_set_num_threads(w[j]);
        printf("------------- w = %d ------------\n", w[j]);
        for (int i = 0; i < 30; i++)
        {
            tempoInicio = omp_get_wtime();

            double tempoInicioMedia = omp_get_wtime();
            CalcularMediasPorCidade(nroRegioes, nroCidades, nroAlunos, nroNotas, notasAlunos, &mediasAlunosCidade);
            double tempoFimMedia = omp_get_wtime();

            double tempoInicioOrdenar = omp_get_wtime();
            GerarTabelas(nroRegioes, nroCidades, nroAlunos, nroNotas, mediasAlunosCidade,
                            &notasPorCidade, &notasPorRegiao, &notasBrasil, &notasPremiacao);
            double tempoFimOrdenar = omp_get_wtime();

            tempoFim = omp_get_wtime();

            printf("Media: %f\n", tempoFimMedia - tempoInicioMedia);
            printf("Ordenar: %f\n", tempoFimOrdenar - tempoInicioOrdenar);
            printf("Total: %f\n", tempoFim - tempoInicio);

            LiberarTabela(mediasAlunosCidade);
            LiberarTabela(notasPorCidade);
            LiberarTabela(notasPorRegiao);
            LiberarTabela(notasBrasil);
            LiberarTabela(notasPremiacao);
        }
    }

    //Fim da seção paralelizável

    /*ImprimirTabela(notasPorCidade);
    ImprimirTabela(notasPorRegiao);
    ImprimirTabela(notasBrasil);
    ImprimirTabela(notasPremiacao);*/

    LiberarTabela(notasAlunos);

    return 0;
}