#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#include <unistd.h>
#include <time.h>

#define NRO_THREADS 100
#define MAX_SLEEP 5000

#define COR_VERMELHA "\033[31m"
#define COR_VERDE   "\033[32m"
#define COR_AZUL    "\033[34m"
#define COR_RESET    "\033[0m"

sem_t tokens[NRO_THREADS];

void *FuncThread(void *arg)
{
    int posicao = *((int*) arg);

    int proxThread = (posicao + 1) % NRO_THREADS;

    sem_wait(&tokens[posicao]);
    
    printf("%sThread %d liberada!\n", COR_VERDE, posicao);

    int tempo = rand() % MAX_SLEEP;
    usleep(tempo);

    sem_post(&tokens[proxThread]);

    tempo = rand() % MAX_SLEEP;
    usleep(tempo);
    
    printf("%sThread %d finalizada!\n", COR_AZUL, posicao);

    pthread_exit(0);
}

int main()
{
    pthread_t threads[NRO_THREADS];
    int posicoes[NRO_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NRO_THREADS; ++i)
    {
        sem_init(&tokens[i], 0 , 0);
        posicoes[i] = i;
    }

    for (int i = 0; i < NRO_THREADS; ++i)
    {
        if (pthread_create(&threads[i], NULL, (void *) FuncThread, (void*) &posicoes[i]) != 0) {
            printf("Error creating thread producer! Exiting! \n");
            exit(0);
        }
    }
    sem_post(&tokens[0]);

    for (int i = 0; i < NRO_THREADS; ++i)
    {
        pthread_join(threads[i], 0);
        sem_destroy(&tokens[i]);
        printf("%sThread %d saindo!\n", COR_VERMELHA, i);
    }

    printf("Thread pai saindo.\n%s", COR_RESET);
	fflush(0);

    return 0;
}