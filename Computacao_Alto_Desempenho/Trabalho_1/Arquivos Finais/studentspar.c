//gcc -O3 -fopenmp studentspar.c -o studentspar -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#define TRUE 1
#define FALSE 0

#define NRO_COLUNAS_TABELAS_NOTAS 5
#define NRO_COLUNAS_TABELA_PREMIACAO 2

#define COLUNA_MIN 0
#define COLUNA_MAX 1
#define COLUNA_MEDIANA 2
#define COLUNA_MEDIA 3
#define COLUNA_DESVIO 4

//Para facilitar a organização
typedef struct
{
    int nroLinhas, nroColunas;
    float **tabela;
} TabelasDados;

void ImprimirTabela(TabelasDados tabela)
{
    for (int i = 0; i < tabela.nroLinhas; ++i)
    {
        for (int j = 0; j < tabela.nroColunas; ++j)
        {
            printf("%.1f ", tabela.tabela[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void LiberarTabela(TabelasDados tabela)
{
    for (int i = 0; i < tabela.nroLinhas; ++i)
        free(tabela.tabela[i]);

    free(tabela.tabela);
}

//Ordena em ordem crescente
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
//tamanhoBlocos é a quantidade de floats dentro de cada bloco de float
void CombinarBlocos(float** dados, const int tam1, const int tam2, const int offset1, const int offset2, float** saida, const int tamanhoBlocos)
{
    int i = 0, j = 0, k = 0;
    int offsetAtual1 = offset1, offsetAtual2 = offset2, offsetAtualSaida = offset1;
    int dadosTotais1 = 0, dadosTotais2 = 0;

    int valoresBlocos1 = tam1 * tamanhoBlocos, valoresBlocos2 = tam2 * tamanhoBlocos;

    //Ordena até que um dos blocos do merge termine
    while (dadosTotais1 < valoresBlocos1 && dadosTotais2 < valoresBlocos2)
    {
        if (dados[offsetAtual1][i] < dados[offsetAtual2][j])
        {
            saida[offsetAtualSaida][k] = dados[offsetAtual1][i];
            AvaliarPosicaoMerge(&i, tamanhoBlocos, &offsetAtual1);
            dadosTotais1++;
        }
        else
        {
            saida[offsetAtualSaida][k] = dados[offsetAtual2][j];
            AvaliarPosicaoMerge(&j, tamanhoBlocos, &offsetAtual2);
            dadosTotais2++;
        }
        AvaliarPosicaoMerge(&k, tamanhoBlocos, &offsetAtualSaida);
    }

    //Coloca o restante do bloco do merge incompleto no final, pois todos os valores são maiores e já ordenados

    while (dadosTotais1 < valoresBlocos1)
    {
        saida[offsetAtualSaida][k] = dados[offsetAtual1][i];
        AvaliarPosicaoMerge(&i, tamanhoBlocos, &offsetAtual1);
        AvaliarPosicaoMerge(&k, tamanhoBlocos, &offsetAtualSaida);
        dadosTotais1++;
    }
    while (dadosTotais2 < valoresBlocos2)
    {
        saida[offsetAtualSaida][k] = dados[offsetAtual2][j];
        AvaliarPosicaoMerge(&j, tamanhoBlocos, &offsetAtual2);
        AvaliarPosicaoMerge(&k, tamanhoBlocos, &offsetAtualSaida);
        dadosTotais2++;
    }
}

//Um merge sort que opera em blocos de tamanhos idênticos
//Extremamente útil para ordenar as regiões e o Brasil, pois é muito mais rápido que o quicksort
void MergeSortBlocos(float **blocos, int tamanhoBloco, int nroBlocos, float *saida)
{
    //Para evitar false sharing
    //Calcula quantos floats devem existir em cada bloco para ocupar as linhas inteiras
    //Linha de 64 bytes -> valor encontrado no cluster de teste do trabalho
    int floatsPorLinha = (64/sizeof(float));
    //(x + y - 1)/y é uma forma de arredondar para cima
    //(15 + 16 - 1 = 30 -> 30/16 = 1.875 = 1) -> 15 floats ocupam 1 linha
    //(18 + 16 - 1 = 33 -> 33/16 = 2.0625 = 2) -> 18 floats ocupam 2 linhas
    int tamanhoLinha = (int)((tamanhoBloco + floatsPorLinha - 1)/floatsPorLinha) * floatsPorLinha;

    int nroBlocosAtuais = nroBlocos;

    float **blocosAtuais = malloc(nroBlocos * sizeof(float*));
    float **juncoes = malloc(nroBlocos * sizeof(float*));
    
    //Tamanhos em blocos do merge, não em bytes nem em valores
    //tamanhoBloco sim é em quantidade de valores de cada bloco do merge
    int *tamanhosAtuais = malloc(nroBlocos * sizeof(int));

    //Quantos blocos de distância da origem
    int *offsets = malloc(nroBlocos * sizeof(int));

    //Copia todos os dados
    for (int i = 0; i < nroBlocos; ++i)
    {
        blocosAtuais[i] = malloc(tamanhoLinha * sizeof(float));
        juncoes[i] = malloc(tamanhoLinha * sizeof(float));

        //Entre o final do bloco e o final da linha ficará lixo, apenas para offset
        memcpy(blocosAtuais[i], blocos[i], tamanhoBloco * sizeof(float));
        tamanhosAtuais[i] = 1;
        offsets[i] = i;
    }

    //Enquanto tiverem blocos para ordenar
    while (nroBlocosAtuais > 1)
    {
        //guided pois os blocos podem ter tamanhos diferentes
        //nroBlocosAtuais/2 -> arredonda para baixo, então descondidera o último se nroBlocosAtuais for ímpar
        #pragma omp parallel for schedule(guided)
        for (int i = 0; i < nroBlocosAtuais/2; ++i)
        {
            //idx = indíce do bloco do merge. Não é em termos de offset
            int idx = 2 * i;
            //Este sim é o offset do bloco atual em termos de blocos de valores, não de blocos de merge
            int offset1 = offsets[idx];
            int offset2 = offsets[idx + 1];
            //Quantidade de valores no bloco de merge
            int tam1 = tamanhosAtuais[idx];
            int tam2 = tamanhosAtuais[idx + 1];

            //Combina os dois blocos de merge
            CombinarBlocos(blocosAtuais, tam1, tam2, offset1, offset2, juncoes, tamanhoBloco);

            //Copia a saída na posição dos dois blocos de merge, formando um único
            //Como eles são adjacentes (idx e idx+1), então é só ir do começo de um até o fim do outro
            for (int j = offset1; j < offset2 + tam2; ++j)
            {
                memcpy(blocosAtuais[j], juncoes[j], tamanhoBloco * sizeof(float));
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
            //Ajusta seu tamanho e offset
            tamanhosAtuais[nroBlocosAtuais/2] = tamanhosAtuais[nroBlocosAtuais-1];
            offsets[nroBlocosAtuais/2] = offsets[nroBlocosAtuais-1];
        }

        //Mesmo princípio do tamanhoLinha: arredondar pra cima
        nroBlocosAtuais = (nroBlocosAtuais + 1) / 2;
    }

    //Copia todos os blocos de merge para a saída
    for (int i = 0; i < nroBlocos; ++i)
    {
        //Como a saída é um vetor e não uma matriz, soma o endereço para acessar a posição correta
        memcpy(saida + i*tamanhoBloco, blocosAtuais[i], tamanhoBloco * sizeof(float));
        free(blocosAtuais[i]);
        free(juncoes[i]);
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
        destino->tabela[i] = malloc(destino->nroColunas * sizeof(*destino->tabela[i]));

        //Como a tabela está ordenada, o mínimo é o primeiro e o máximo é o último
        destino->tabela[i][COLUNA_MIN] = dados.tabela[i][0];
        destino->tabela[i][COLUNA_MAX] = dados.tabela[i][dados.nroColunas-1];
        destino->tabela[i][COLUNA_MEDIANA] = MedianaDoVetor(dados.tabela[i], dados.nroColunas);
        float media = MediaDoVetor(dados.tabela[i], dados.nroColunas);
        destino->tabela[i][COLUNA_MEDIA] = media;
        destino->tabela[i][COLUNA_DESVIO] = DesvioPadraoDoVetor(dados.tabela[i], dados.nroColunas, media);

        if (deveProcurarMax == TRUE)
        {
            if (destino->tabela[i][COLUNA_MAX] > destino->tabela[max][COLUNA_MAX])
                max = i;
        }
    }

    //Retorna o indíce do valor máximo encontrado
    return max;
}

void GerarNotas(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, TabelasDados *notasAlunos)
{
    //nroRegioes * nroCidades * nroAlunos = (regiao, cidade, aluno)
    notasAlunos->nroLinhas = nroRegioes * nroCidades * nroAlunos;
    notasAlunos->nroColunas = nroNotas;
    notasAlunos->tabela = malloc(notasAlunos->nroLinhas * sizeof(*notasAlunos->tabela));

    for (int i = 0; i < notasAlunos->nroLinhas; ++i)
    {
        notasAlunos->tabela[i] = malloc(notasAlunos->nroColunas * sizeof(**notasAlunos->tabela));
        for (int j = 0; j < nroNotas; ++j)
        {
            //rand()/RAND_MAX = float entre 0.0 e 1.0
            notasAlunos->tabela[i][j] = (float)rand() / (float)RAND_MAX * 100;
        }
    }
}

void CalcularMediasPorCidade(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, 
                        TabelasDados notasAlunos, TabelasDados *mediasAlunosCidade)
{
    mediasAlunosCidade->nroLinhas = nroRegioes * nroCidades;
    mediasAlunosCidade->nroColunas = nroAlunos;
    mediasAlunosCidade->tabela = malloc(mediasAlunosCidade->nroLinhas * sizeof(*mediasAlunosCidade->tabela));

    //https://stackoverflow.com/questions/10706466/how-does-malloc-work-in-a-multithreaded-environment
    //malloc impõe mutex, então é favorável chamá-los fora da seção paralela
    for (int i = 0; i < mediasAlunosCidade->nroLinhas; ++i)
        mediasAlunosCidade->tabela[i] = malloc(mediasAlunosCidade->nroColunas * sizeof(*mediasAlunosCidade->tabela[i]));

    //Transformar o loop aninhado em um único loop melhora o balanceamento de carga e simplifica a paralelização
    //Poderia usar collapse(2), mas deste jeito dá controle explícito sobre o padrão de acesso à memória
    double calcularMediasInicio = omp_get_wtime();
    int total = mediasAlunosCidade->nroLinhas * mediasAlunosCidade->nroColunas;
    #pragma omp parallel for schedule(static)
    for (int idx = 0; idx < total; ++idx)
    {
        //A função MediaDoVetor é pesada o suficiente para estas operações extras serem negligenciáveis
        int i = idx / mediasAlunosCidade->nroColunas;
        int j = idx % mediasAlunosCidade->nroColunas;

        mediasAlunosCidade->tabela[i][j] = MediaDoVetor(notasAlunos.tabela[i*nroAlunos + j], nroNotas);
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
    mediasPorRegiao.tabela = malloc(mediasPorRegiao.nroLinhas * sizeof(*mediasPorRegiao.tabela));

    for (int i = 0; i < nroRegioes; i++)
        mediasPorRegiao.tabela[i] = malloc(mediasPorRegiao.nroColunas * sizeof(*mediasPorRegiao.tabela[i]));

    mediasBrasil.nroLinhas = 1;
    mediasBrasil.nroColunas = nroRegioes * nroCidades * nroAlunos;
    mediasBrasil.tabela = malloc(mediasBrasil.nroLinhas * sizeof(*mediasBrasil.tabela));

    //============== Esta seção copia os dados para as outras tabelas e as ordena ==============
    
    #pragma omp parallel
    {
        //Ordena os blocos das cidades
        //Isso vai ser útil para ordenar os restantes, pois permite usar um merge sort adaptado, que é mais otimizado que o quicksort
        #pragma omp for schedule(static)
        for (int i = 0; i < nroRegioes * nroCidades; ++i)
        {
            OrdenarArray(mediasAlunosCidade.tabela[i], mediasAlunosCidade.nroColunas);
        }

        //Com as cidades ordenadas, dá pra usar um merge sort nas regiões
        //O merge neste caso está programado para lidar exatamente com os blocos da cidade,
        //então é o mais otimizado possível

        #pragma omp for schedule(static)
        for (int i = 0; i < nroRegioes; i++)
        {
            MergeSortBlocos(&mediasAlunosCidade.tabela[i * nroCidades], nroAlunos, nroCidades, mediasPorRegiao.tabela[i]);
        }
    }

    //Com as regiões ordenadas, dá pra usar um merge sort no Brasil

    mediasBrasil.tabela[0] = malloc(mediasBrasil.nroColunas * sizeof(*mediasBrasil.tabela[0]));
    MergeSortBlocos(mediasPorRegiao.tabela, nroCidades * nroAlunos, nroRegioes, mediasBrasil.tabela[0]);

    //============== Este trecho instancia as tabelas ============== 

    notasPorCidade->nroLinhas = mediasAlunosCidade.nroLinhas;
    notasPorCidade->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasPorCidade->tabela = malloc(notasPorCidade->nroLinhas * sizeof(*notasPorCidade->tabela));

    notasPorRegiao->nroLinhas = mediasPorRegiao.nroLinhas;
    notasPorRegiao->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasPorRegiao->tabela = malloc(notasPorRegiao->nroLinhas * sizeof(*notasPorRegiao->tabela));

    notasBrasil->nroLinhas = mediasBrasil.nroLinhas;
    notasBrasil->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasBrasil->tabela = malloc(notasBrasil->nroLinhas * sizeof(*notasBrasil->tabela));

    //Linha da região e linha da cidade
    notasPremiacao->nroLinhas = 2;
    notasPremiacao->nroColunas = NRO_COLUNAS_TABELA_PREMIACAO;
    notasPremiacao->tabela = malloc(notasPremiacao->nroLinhas * sizeof(*notasPremiacao->tabela));

    //============== Este trecho organiza as tabelas ==============

    //Este trecho do código é tão simples que paralelizá-lo ia aumentar o tempo por overhead

    int melhorRegiao = 0, melhorCidade = 0;

    melhorCidade = MontarTabelaImpressao(notasPorCidade, mediasAlunosCidade, TRUE);
    melhorRegiao = MontarTabelaImpressao(notasPorRegiao, mediasPorRegiao, TRUE);
    MontarTabelaImpressao(notasBrasil, mediasBrasil, FALSE);
    
    notasPremiacao->tabela[0] = malloc(notasPremiacao->nroColunas * sizeof(*notasPremiacao->tabela[0]));
    notasPremiacao->tabela[0][0] = melhorRegiao;
    notasPremiacao->tabela[0][1] = notasPorRegiao->tabela[melhorRegiao][COLUNA_MAX];

    notasPremiacao->tabela[1] = malloc(notasPremiacao->nroColunas * sizeof(*notasPremiacao->tabela[1]));
    notasPremiacao->tabela[1][0] = melhorCidade;
    notasPremiacao->tabela[1][1] = notasPorCidade->tabela[melhorCidade][COLUNA_MAX];

    //============== Este trecho libera as tabelas auxiliares ==============

    LiberarTabela(mediasBrasil);
    LiberarTabela(mediasPorRegiao);
}

int main()
{
    double tempoInicio, tempoFim;
    int nroRegioes, nroCidades, nroAlunos, nroNotas, limiteThreads, seed;

    scanf("%d %d %d %d %d %d", &nroRegioes, &nroCidades, &nroAlunos, &nroNotas, &limiteThreads, &seed);

    srand(seed);
    //Garante que não terá aninhamento de threads
    omp_set_nested(0);
    omp_set_num_threads(limiteThreads);
    
    TabelasDados notasAlunos, mediasAlunosCidade, notasPorCidade, notasPorRegiao, notasBrasil, notasPremiacao;

    double tempoInicioGerar = omp_get_wtime();
    GerarNotas(nroRegioes, nroCidades, nroAlunos, nroNotas, &notasAlunos);
    double tempoFimGerar = omp_get_wtime();
    printf("Geracao: %f\n", tempoFimGerar - tempoInicioGerar);

    //Início da seção paralelizável

    tempoInicio = omp_get_wtime();

    double tempoInicioMedia = omp_get_wtime();
    CalcularMediasPorCidade(nroRegioes, nroCidades, nroAlunos, nroNotas, notasAlunos, &mediasAlunosCidade);
    double tempoFimMedia = omp_get_wtime();

    double tempoInicioOrdenar = omp_get_wtime();
    GerarTabelas(nroRegioes, nroCidades, nroAlunos, nroNotas, mediasAlunosCidade,
                    &notasPorCidade, &notasPorRegiao, &notasBrasil, &notasPremiacao);
    double tempoFimOrdenar = omp_get_wtime();

    tempoFim = omp_get_wtime();

    //Fim da seção paralelizável

    printf("Media: %f\n", tempoFimMedia - tempoInicioMedia);
    printf("Ordenar: %f\n", tempoFimOrdenar - tempoInicioOrdenar);
    printf("Total: %f\n", tempoFim - tempoInicio);

    /*ImprimirTabela(notasPorCidade);
    ImprimirTabela(notasPorRegiao);
    ImprimirTabela(notasBrasil);
    ImprimirTabela(notasPremiacao);*/

    LiberarTabela(notasAlunos);
    LiberarTabela(mediasAlunosCidade);
    LiberarTabela(notasPorCidade);
    LiberarTabela(notasPorRegiao);
    LiberarTabela(notasBrasil);
    LiberarTabela(notasPremiacao);

    return 0;
}