#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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
    float *tabela;
} TabelasDados;

void ImprimirTabela(TabelasDados tabela)
{
    for (int i = 0; i < tabela.nroLinhas; ++i)
    {
        for (int j = 0; j < tabela.nroColunas; ++j)
        {
            printf("%.1f ", tabela.tabela[i*tabela.nroColunas + j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

//Ordena em ordem crescente
int FuncaoComparacao(const void *nota1, const void *nota2)
{
    float x = *(const float*)nota1;
    float y = *(const float*)nota2;
    return (x > y) - (x < y);
}

void OrdenarArray(float* array, int primeiro, int nroItens)
{
    //Função de ordenação do stdlib.h
    qsort(array + primeiro, nroItens, sizeof(*array), FuncaoComparacao);
}

float MediaDoVetor(float* array, int primeiro, int nroItens)
{
    float media = 0;
    for(int i = primeiro; i < primeiro + nroItens; ++i)
    {
        media += array[i];
    }
    return media/nroItens;
}

float MedianaDoVetor(float* array, int primeiro, int nroItens)
{
    //Número ímpar de itens, então a mediana é o central
    if (nroItens % 2 == 1)
    {
        //(int) arredonda para baixo
        //Como a contagem começa em 0, então é a mediana exata
        return array[primeiro + (int)nroItens/2];
    }
    //Número par de itens, então a mediana é a média dos 2 ao redor do meio
    else
    {
        //Como a contagem começa em 0, então pega o abaixo da metade e a metade
        int pos = primeiro + nroItens/2;
        float aux = 0.0;

        aux += array[pos - 1];
        aux += array[pos];
        return aux/2.0;
    }
}

float DesvioPadraoDoVetor(float* array, int primeiro, int nroItens, float media)
{
    float soma = 0, aux;

    for (int i = primeiro; i < primeiro + nroItens; i++) {
        aux = array[i] - media;
        soma += aux * aux;
    }

    return sqrt(soma / nroItens);
}

int MontarTabelaImpressao(TabelasDados *destino, TabelasDados dados, int deveProcurarMax)
{
    int max = -1;
    if (deveProcurarMax == TRUE)
        max = 0;

    for (int i = 0; i < destino->nroLinhas; ++i)
    {
        //Como a tabela está ordenada, o mínimo é o primeiro e o máximo é o último
        destino->tabela[i * destino->nroColunas + COLUNA_MIN] = dados.tabela[i * dados.nroColunas];
        destino->tabela[i * destino->nroColunas + COLUNA_MAX] = dados.tabela[i * dados.nroColunas + dados.nroColunas-1];
        destino->tabela[i * destino->nroColunas + COLUNA_MEDIANA] = 
                                                    MedianaDoVetor(dados.tabela, i * dados.nroColunas, dados.nroColunas);

        float media = MediaDoVetor(dados.tabela, i * dados.nroColunas, dados.nroColunas);
        destino->tabela[i * destino->nroColunas + COLUNA_MEDIA] = media;
        destino->tabela[i * destino->nroColunas + COLUNA_DESVIO] = 
                                    DesvioPadraoDoVetor(dados.tabela, i * dados.nroColunas, dados.nroColunas, media);

        if (deveProcurarMax == TRUE)
        {
            if (destino->tabela[i * destino->nroColunas + COLUNA_MAX] > destino->tabela[max * destino->nroColunas + COLUNA_MAX])
                max = i;
        }
    }

    return max;
}

void GerarNotas(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, TabelasDados *notasAlunos)
{
    //nroRegioes * nroCidades * nroAlunos = (regiao, cidade, aluno)
    notasAlunos->nroLinhas = nroRegioes * nroCidades * nroAlunos;
    notasAlunos->nroColunas = nroNotas;
    notasAlunos->tabela = malloc(notasAlunos->nroLinhas * notasAlunos->nroColunas * sizeof(*notasAlunos->tabela));

    for (int i = 0; i < notasAlunos->nroLinhas * notasAlunos->nroColunas; ++i)
    {
        //rand()/RAND_MAX = float entre 0.0 e 1.0
        notasAlunos->tabela[i] = (float)rand() / (float)RAND_MAX * 100;
    }
}

void CalcularMediasPorCidade(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, 
                        TabelasDados notasAlunos, TabelasDados *mediasAlunosCidade)
{
    mediasAlunosCidade->nroLinhas = nroRegioes * nroCidades;
    mediasAlunosCidade->nroColunas = nroAlunos;
    mediasAlunosCidade->tabela = malloc(mediasAlunosCidade->nroLinhas * mediasAlunosCidade->nroColunas * sizeof(*mediasAlunosCidade->tabela));
    for (int i = 0; i < mediasAlunosCidade->nroLinhas * mediasAlunosCidade->nroColunas; ++i)
    {
        mediasAlunosCidade->tabela[i] = MediaDoVetor(notasAlunos.tabela, i*nroNotas, nroNotas);
    }
}

void GerarTabelas(int nroRegioes, int nroCidades, int nroAlunos, int nroNotas, TabelasDados mediasAlunosCidade, 
                    TabelasDados *notasPorCidade, TabelasDados *notasPorRegiao, 
                    TabelasDados *notasBrasil, TabelasDados *notasPremiacao)
{
    //============== Este primeiro trecho separa os dados para cada análise, já ordenando-os ============== 

    TabelasDados mediasPorRegiao, mediasBrasil;
    
    mediasPorRegiao.nroLinhas = nroRegioes;
    mediasPorRegiao.nroColunas = nroCidades * nroAlunos;
    mediasPorRegiao.tabela = malloc(mediasPorRegiao.nroLinhas * mediasPorRegiao.nroColunas * sizeof(*mediasPorRegiao.tabela));

    mediasBrasil.nroLinhas = 1;
    mediasBrasil.nroColunas = nroRegioes * nroCidades * nroAlunos;
    mediasBrasil.tabela = malloc(mediasBrasil.nroLinhas * mediasBrasil.nroColunas * sizeof(*mediasBrasil.tabela));

    memcpy(mediasPorRegiao.tabela, mediasAlunosCidade.tabela, 
                mediasAlunosCidade.nroLinhas * mediasAlunosCidade.nroColunas * sizeof(*mediasAlunosCidade.tabela));
    memcpy(mediasBrasil.tabela, mediasAlunosCidade.tabela, 
                mediasAlunosCidade.nroLinhas * mediasAlunosCidade.nroColunas * sizeof(*mediasAlunosCidade.tabela));

    for (int i = 0; i < nroRegioes; ++i)
    {
        for (int j = 0; j < nroCidades; ++j)
        {
            OrdenarArray(mediasAlunosCidade.tabela, (i*nroCidades + j)*nroAlunos, mediasAlunosCidade.nroColunas);
        }
        OrdenarArray(mediasPorRegiao.tabela, i*nroCidades*nroAlunos, mediasPorRegiao.nroColunas);
    }
    OrdenarArray(mediasBrasil.tabela, 0, mediasBrasil.nroColunas);

    //============== Este trecho instancia as tabelas ============== 

    notasPorCidade->nroLinhas = mediasAlunosCidade.nroLinhas;
    notasPorCidade->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasPorCidade->tabela = malloc(notasPorCidade->nroLinhas * notasPorCidade->nroColunas * sizeof(*notasPorCidade->tabela));

    notasPorRegiao->nroLinhas = mediasPorRegiao.nroLinhas;
    notasPorRegiao->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasPorRegiao->tabela = malloc(notasPorRegiao->nroLinhas * notasPorRegiao->nroColunas * sizeof(*notasPorRegiao->tabela));

    notasBrasil->nroLinhas = mediasBrasil.nroLinhas;
    notasBrasil->nroColunas = NRO_COLUNAS_TABELAS_NOTAS;
    notasBrasil->tabela = malloc(notasBrasil->nroLinhas * notasBrasil->nroColunas * sizeof(*notasBrasil->tabela));

    //Linha da região e linha da cidade
    notasPremiacao->nroLinhas = 2;
    notasPremiacao->nroColunas = NRO_COLUNAS_TABELA_PREMIACAO;
    notasPremiacao->tabela = malloc(notasPremiacao->nroLinhas * notasPremiacao->nroColunas * sizeof(*notasPremiacao->tabela));

    //============== Este trecho organiza as tabelas ==============

    int melhorRegiao = 0, melhorCidade = 0;

    melhorCidade = MontarTabelaImpressao(notasPorCidade, mediasAlunosCidade, TRUE);
    melhorRegiao = MontarTabelaImpressao(notasPorRegiao, mediasPorRegiao, TRUE);
    MontarTabelaImpressao(notasBrasil, mediasBrasil, FALSE);
    
    notasPremiacao->tabela[0 * notasPremiacao->nroColunas + 0] = melhorRegiao;
    notasPremiacao->tabela[0 * notasPremiacao->nroColunas + 1] = 
                        notasPorRegiao->tabela[melhorRegiao * notasPorRegiao->nroColunas + COLUNA_MAX];

    notasPremiacao->tabela[1 * notasPremiacao->nroColunas + 0] = melhorCidade;
    notasPremiacao->tabela[1 * notasPremiacao->nroColunas + 1] = 
                        notasPorCidade->tabela[melhorCidade  * notasPorCidade->nroColunas + COLUNA_MAX];

    //============== Este trecho libera as tabelas ==============

    free(mediasBrasil.tabela);
    free(mediasPorRegiao.tabela);
}

int main()
{
    clock_t tempoInicio, tempoFim;
    int nroRegioes, nroCidades, nroAlunos, nroNotas, limiteThreads, seed;

    scanf("%d %d %d %d %d %d", &nroRegioes, &nroCidades, &nroAlunos, &nroNotas, &limiteThreads, &seed);

    srand(seed);
    
    TabelasDados notasAlunos, mediasAlunosCidade, notasPorCidade, notasPorRegiao, notasBrasil, notasPremiacao;
    GerarNotas(nroRegioes, nroCidades, nroAlunos, nroNotas, &notasAlunos);

    tempoInicio = clock();

    CalcularMediasPorCidade(nroRegioes, nroCidades, nroAlunos, nroNotas, notasAlunos, &mediasAlunosCidade);
    GerarTabelas(nroRegioes, nroCidades, nroAlunos, nroNotas, mediasAlunosCidade,
                    &notasPorCidade, &notasPorRegiao, &notasBrasil, &notasPremiacao);

    tempoFim = clock();

    /*ImprimirTabela(notasPorCidade);
    ImprimirTabela(notasPorRegiao);
    ImprimirTabela(notasBrasil);
    ImprimirTabela(notasPremiacao);*/

    printf("%f", ((double)(tempoFim - tempoInicio))/CLOCKS_PER_SEC);

    free(notasAlunos.tabela);
    free(mediasAlunosCidade.tabela);
    free(notasPorCidade.tabela);
    free(notasPorRegiao.tabela);
    free(notasBrasil.tabela);
    free(notasPremiacao.tabela);

    return 0;
}