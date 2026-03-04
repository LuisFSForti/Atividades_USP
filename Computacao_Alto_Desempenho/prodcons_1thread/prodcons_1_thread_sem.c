#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_PRODUCED 27
#define MAX_QUEUE 7

#define PRODUCERS 500
#define CONSUMERS 500

sem_t  mutex, empty, full;

int queue[MAX_QUEUE], item_available=0, produced=0, consumed=0;


int create_item(void) {

	return(rand()%1000);

} //fim  create_item()

void insert_into_queue(int item) {

	queue[item_available++] = item;
	produced++;
	printf("producing item:%d, value:%d, queued:%d \n", produced, item, item_available);
	return;

} // fim insert_into_queue()

int extract_from_queue() {

	consumed++;
	printf("cosuming item:%d, value:%d, queued:%d \n", consumed, queue[item_available-1], item_available-1);

	return(queue[--item_available]);

} // fim extract_from_queue()

void process_item(int my_item) {
	static int printed=0;

	printf("Printed:%d, value:%d, queued:%d \n", printed++, my_item, item_available);

	return;

} // fim_process_item()


void *producer(void) {
	int item;

	//while (true)
	while (1) {
		item = create_item();
		sem_wait(&empty);
		sem_wait(&mutex);

		if (produced < MAX_PRODUCED)
		{
			insert_into_queue(item);
			sem_post(&mutex);
			sem_post(&full);
		}
		//Se não deve inserir um produto, aumenta o empty de volta
		//Tinha vazio -> não fiz nada -> continua vazio
		//Assim consegue matar todos os produtores
		else
		{
			sem_post(&mutex);
			sem_post(&empty);

			//Sai do loop, não tem mais o que adicionar
			break;
		}
	}

	printf("Thread producer saindo.\n");
	fflush(0);

	pthread_exit(0);
} // fim producer

void *consumer(void) {
	int my_item = 0;

	//while (true)
	while (1) {
		//Por conta de uma gambiarra no main, depois de consumir tudo ainda sobrará 1 full
		sem_wait(&full);
		sem_wait(&mutex);

		if (consumed < MAX_PRODUCED)
		{
			my_item = extract_from_queue();
			sem_post(&mutex);
			sem_post(&empty);

			process_item(my_item);
		}
		//Se já consumiu o limite de itens, aumenta o full de volta
		//Como tem 1 full sobrando que se renova, isso será o suficiente para matar todos os consumidores
		else
		{
			sem_post(&mutex);
			sem_post(&full);

			//Sai do loop, não tem mais o que consumir
			break;
		}
	}

	printf("Thread consumer saindo.\n");
	fflush(0);

	pthread_exit(0);
} // fim_consumer


int main(void) {
	pthread_t *prod_handle, *cons_handle;

	//Os vetores de threads
	prod_handle = malloc(PRODUCERS * sizeof(*prod_handle));
	cons_handle = malloc(CONSUMERS * sizeof(*cons_handle));

	/* declarations and initializations */
	item_available = 0;

	sem_init(&mutex, 0 , 1);
	sem_init(&empty, 0, MAX_QUEUE);
	sem_init(&full, 0, 0);

	//Cria todas as threads
	for (int i = 0; i < PRODUCERS; ++i)
    {
        if (pthread_create(&prod_handle[i], 0, (void *) producer, (void *) 0) != 0) {
            printf("Error creating thread producer! Exiting! \n");
            exit(0);
        }
    }
    for (int i = 0; i < CONSUMERS; ++i)
    {
        if (pthread_create(&cons_handle[i], 0, (void *) consumer, (void *) 0) != 0) {
            printf("Error creating thread consumer! Exiting! \n");
            exit(0);
        }
    }
	printf("\n Father's thread waiting for his kids.\n\n");
	fflush(0);

	//Espera todos os produtores encerrarem
    for (int i = 0; i < PRODUCERS; ++i)
        pthread_join(prod_handle[i], 0);

	//Aumenta o full em 1, serve para auxiliar os consumidores a encerrarem
	//Esse 1 extra vai fazer o full ser 1 mesmo depois de todos os itens serem consumidos
	sem_post(&full);
    for (int i = 0; i < CONSUMERS; ++i)
        pthread_join(cons_handle[i], 0);

	printf("Thread pai saindo.\n");
	fflush(0);

	exit(0);
} // main()
