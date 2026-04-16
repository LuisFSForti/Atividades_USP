//gcc -fopenmp studentspar.c -o studentspar -lm

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
    qsort(array, nroItens, sizeof(*array), FuncaoComparacao);
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

    //https://stackoverflow.com/questions/10706466/how-does-malloc-work-in-a-multithreaded-environment
    //malloc impõe mutex, então é favorável chamá-los fora da seção paralela
    for (int i = 0; i < mediasAlunosCidade->nroLinhas; ++i)
        mediasAlunosCidade->tabela[i] = malloc(mediasAlunosCidade->nroColunas * sizeof(*mediasAlunosCidade->tabela[i]));

    //Transformando o loop aninhando em um único grande loop garantimos que a paralelização ocorrerá o melhor possível
    //Usando o aninhamento dos loops, seriam necessários dois #pragma for e uma série de análises para quantas threads cada um usaria
    //Juntando num único for podemos operar diretamente no total, sem dificuldades
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
    printf("Calcular medias: %f\n", omp_get_wtime() - calcularMediasInicio);
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

    mediasBrasil.nroLinhas = 1;
    mediasBrasil.nroColunas = nroRegioes * nroCidades * nroAlunos;
    mediasBrasil.tabela = malloc(mediasBrasil.nroLinhas * sizeof(*mediasBrasil.tabela));

    //============== Esta seção copia os dados para as outras tabelas ==============
    //memcpy é uma função muito otimizada pelo processador. Ela nativamente usa mecanismos SIMD e afins
    //Paralelizar esta seção é prejudicial, pois cria overhead pra ciração e sincronização das threads

    //todasNotasBrasil.tabela -> todas as notas médias num único array
    //Como só tem 1 linha, instancia na posição 0
    //Poderia usar apenas um array, mas desta forma mantém o padrão de leitura por pouco prejuízo
    mediasBrasil.tabela[0] = malloc(mediasBrasil.nroColunas * sizeof(*mediasBrasil.tabela[0]));                       
    for (int i = 0; i < nroRegioes; ++i)
    {
        mediasPorRegiao.tabela[i] = malloc(mediasPorRegiao.nroColunas * sizeof(*mediasPorRegiao.tabela[i]));
        for (int j = 0; j < nroCidades; ++j)
        {
            memcpy(&mediasPorRegiao.tabela[i][j * nroAlunos],
                mediasAlunosCidade.tabela[i * nroCidades + j],
                mediasAlunosCidade.nroColunas * sizeof(**mediasAlunosCidade.tabela));

            memcpy(&mediasBrasil.tabela[0][i * nroCidades * nroAlunos + j * nroAlunos],
                mediasAlunosCidade.tabela[i * nroCidades + j],
                mediasAlunosCidade.nroColunas * sizeof(**mediasAlunosCidade.tabela));
        }
    }

    //============== Esta seção ordena os dados para as outras tabelas ==============
    //A função OrdenarArray() usa qsort(), a implementação de quicksort do C
    //Quicksort é O(n log(n)). Então a ordem de maior custo SEMPRE vai ser -> mediasBrasil, mediasPorRegiao e mediasAlunosCidade
    //Então o mediasBrasil sempre será o mais custoso, além de não ser paralelizável (pois é um único array)
    //Em suma, é vantajoso dar para o mediasBrasil sua própria thread o mais rápido possível, que sempre será o gargalo

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            {
                OrdenarArray(mediasBrasil.tabela[0], mediasBrasil.nroColunas);
            }
            #pragma omp task
            {
                for (int i = 0; i < nroRegioes; ++i)
                {
                    #pragma omp task
                    OrdenarArray(mediasPorRegiao.tabela[i], mediasPorRegiao.nroColunas);
                }
            }
            #pragma omp task
            {
                for (int i = 0; i < nroRegioes; ++i)
                {
                    //A task fica dentro do loop, deixando loops para ela cuidar
                    //Assim não cria tasks de granunalidade fina demais, que teriam muito overhead
                    #pragma omp task
                    for (int j = 0; j < nroCidades; ++j)
                    {
                        OrdenarArray(mediasAlunosCidade.tabela[i * nroCidades + j], mediasAlunosCidade.nroColunas);
                    }
                }
            }
        }
    }

    //============== Este trecho instancia as tabelas ============== 

    //Este trecho do código é tão simples que paralelizá-lo ia aumentar o tempo por overhead

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
    printf("Media: %f\n", tempoFimMedia - tempoInicioMedia);

    double tempoInicioOrdenar = omp_get_wtime();
    GerarTabelas(nroRegioes, nroCidades, nroAlunos, nroNotas, mediasAlunosCidade,
                    &notasPorCidade, &notasPorRegiao, &notasBrasil, &notasPremiacao);
    double tempoFimOrdenar = omp_get_wtime();
    printf("Ordenar: %f\n", tempoFimOrdenar - tempoInicioOrdenar);

    tempoFim = omp_get_wtime();

    //Fim da seção paralelizável

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