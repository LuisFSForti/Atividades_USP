//mpicc limiar.c -o limiar
//mpirun --use-hwthread-cpus ./limiar < entrada.txt
//--use-hwthread-cpus == núcleos do hardware

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int* LerArquivo(int *tamVet, int *limiar)
{
    int i, tam, posLimiar;
    int *vet;
    char *inputfilename;

    scanf("%d", &tam);
    scanf("%d", &posLimiar);

    //printf("tam=%d k=%d\n", tam, posLimiar);
    fflush(0);

    if(posLimiar < 0 || posLimiar > (tam-1)){
        printf("K value is outside of vet's range. \n");
        exit(1);
    }

    vet = (int*)malloc(tam*sizeof(int));

    for(i=0;i<tam;i++){
        scanf("%d", &vet[i]);
    }

    *tamVet = tam;
    *limiar = vet[posLimiar];

    return vet;
}

int main(int argc, char *argv[])
{
    //Globais
    int tam = 0, limiar = 0;
    int *valores, *indices;

    //Por processo
    int rank, size;
    int posInicio, posFim, contagem, somaTotal;
    //Apenas do processo-mestre (rank == 0)
    int *counts = NULL, *displs = NULL, *indicesTotal = NULL;

    MPI_Init(&argc, &argv);

    // Todos os processos pertencem ao mesmo comunicador
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    //Processo mestre
    if (rank == 0)
    {
        valores = LerArquivo(&tam, &limiar);
    }

    MPI_Bcast(&tam, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&limiar, 1, MPI_INT, 0, MPI_COMM_WORLD);

    //Todo processo não mestre
    if (rank != 0)
    {
        valores = (int*)malloc(tam * sizeof(int));
    }
    MPI_Bcast(valores, tam, MPI_INT, 0, MPI_COMM_WORLD);

    //Como posFim(x) = posInicio(x+1), [posInicio, posFim)
    posInicio = rank * tam / size;
    posFim = (rank + 1) * tam / size;

    contagem = 0;

    indices = (int*)malloc(sizeof(int));
    for (int i = posInicio; i < posFim; i++)
    {
        if (valores[i] > limiar)
        {
            contagem++;
            indices = (int*)realloc(indices, contagem*sizeof(int));
            indices[contagem-1] = i;
        }
    }

    if(rank == 0)
    {
        counts = (int*)malloc(size * sizeof(int));
        displs = (int*)malloc(size * sizeof(int));
    }

    //Recolhe as contagens de cada processo
    //Ele naturalmente recolher por ordem crescente de rank
    MPI_Gather(
        &contagem,
        1,
        MPI_INT,

        counts,
        1,
        MPI_INT,

        0,
        MPI_COMM_WORLD
    );

    if(rank == 0)
    {
        int offset = 0;

        //Calcula em que posição iniciam os indíces enviados por cada processo
        //Ex: se o rank 0 encontrou 4 indíces, o primeiro do rank 1 começa em indicesTotal[4]
        //Nesse caso, displs[1] == 4
        for(int i = 0; i < size; i++)
        {
            displs[i] = offset;
            offset += counts[i];
        }

        somaTotal = offset;
        indicesTotal = (int*)malloc(somaTotal * sizeof(int));
    }

    //Recolhe os indíces dos outros processos
    //counts define quanto deve coletar de cada processo,
    //com displs definindo onde começa a salvar em indicesTotal
    MPI_Gatherv(
        indices,
        contagem,
        MPI_INT,

        indicesTotal,
        counts,
        displs,
        MPI_INT,

        0,
        MPI_COMM_WORLD
    );

    if(rank == 0)
    {
        printf("Total = %d\n", somaTotal);

        for(int i = 0; i < somaTotal; i++)
        {
            printf("%d ", indicesTotal[i]);
        }

        printf("\n");
    }

    free(valores);
    free(indices);
    if(rank == 0)
    {
        free(indicesTotal);
        free(counts);
        free(displs);
    }

    MPI_Finalize();

    return 0;
}