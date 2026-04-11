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
    qsort(array, nroItens, sizeof(*array), FuncaoComparacao);
}

float MediaDoVetor(float* array, int nroItens)
{
    float media = 0;
    for(int i = 0; i < nroItens; ++i)
    {
        media += array[i];
    }
    return media/nroItens;
}

float MedianaDoVetor(float* array, int nroItens)
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

float DesvioPadraoDoVetor(float* array, int nroItens, float media)
{
    float soma = 0, aux;

    for (int i = 0; i < nroItens; i++) {
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
        destino->tabela[i] = malloc(destino->nroColunas * sizeof(*destino->tabela[i]));

        //Como a tabela está ordenada, o mínimo é o primeiro e o máximo é o último
        destino->tabela[i][COLUNA_MIN] = dados.tabela[i][0];
        destino->tabela[i][COLUNA_MAX] = dados.tabela[i][dados.nroColunas-1];
        destino->tabela[i][COLUNA_MEDIANA] = MedianaDoVetor(dados.tabela[i], dados.nroColunas);
        float media = MediaDoVetor(dados.tabela[i], dados.nroColunas);
        destino->tabela[i][COLUNA_MEDIA] = media;
        destino->tabela[i][COLUNA_DESVIO] = 
                                    DesvioPadraoDoVetor(dados.tabela[i], dados.nroColunas, media);

        if (deveProcurarMax == TRUE)
        {
            if (destino->tabela[i][COLUNA_MAX] > destino->tabela[max][COLUNA_MAX])
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
    for (int i = 0; i < mediasAlunosCidade->nroLinhas; ++i)
    {
        mediasAlunosCidade->tabela[i] = malloc(mediasAlunosCidade->nroColunas * sizeof(*mediasAlunosCidade->tabela[i]));
        
        for (int j = 0; j < mediasAlunosCidade->nroColunas; ++j)
        {
            mediasAlunosCidade->tabela[i][j] = MediaDoVetor(notasAlunos.tabela[i*nroAlunos + j], nroNotas);
        }
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
    mediasPorRegiao.tabela = malloc(mediasPorRegiao.nroLinhas * sizeof(*mediasPorRegiao.tabela));

    mediasBrasil.nroLinhas = 1;
    mediasBrasil.nroColunas = nroRegioes * nroCidades * nroAlunos;
    mediasBrasil.tabela = malloc(mediasBrasil.nroLinhas * sizeof(*mediasBrasil.tabela));

    //todasNotasBrasil.tabela -> todas as notas médias num único array
    //Como só tem 1 linha, instancia na posição 0
    //Poderia usar apenas um array, mas desta forma mantém o padrão de leitura por pouco prejuízo
    mediasBrasil.tabela[0] = malloc(mediasBrasil.nroColunas * sizeof(*mediasBrasil.tabela[0]));                                    
    for (int i = 0; i < nroRegioes; ++i)
    {
        //todasNotasPorRegiao.tabela -> separa todas as notas por região
        mediasPorRegiao.tabela[i] = malloc(mediasPorRegiao.nroColunas * sizeof(*mediasPorRegiao.tabela[i]));
        for (int j = 0; j < nroCidades; ++j)
        {
            memcpy(&mediasPorRegiao.tabela[i][j * nroAlunos],
                        mediasAlunosCidade.tabela[i * nroCidades + j], 
                        mediasAlunosCidade.nroColunas * sizeof(**mediasAlunosCidade.tabela));

            memcpy(&mediasBrasil.tabela[0][i * nroCidades * nroAlunos + j * nroAlunos],
                        mediasAlunosCidade.tabela[i * nroCidades + j],
                        mediasAlunosCidade.nroColunas * sizeof(**mediasAlunosCidade.tabela));

            OrdenarArray(mediasAlunosCidade.tabela[i * nroCidades + j], mediasAlunosCidade.nroColunas);
        }
        OrdenarArray(mediasPorRegiao.tabela[i], mediasPorRegiao.nroColunas);
    }
    OrdenarArray(mediasBrasil.tabela[0], mediasBrasil.nroColunas);

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

    //============== Este trecho libera as tabelas ==============

    LiberarTabela(mediasBrasil);
    LiberarTabela(mediasPorRegiao);
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

    LiberarTabela(notasAlunos);
    LiberarTabela(mediasAlunosCidade);
    LiberarTabela(notasPorCidade);
    LiberarTabela(notasPorRegiao);
    LiberarTabela(notasBrasil);
    LiberarTabela(notasPremiacao);

    return 0;
}