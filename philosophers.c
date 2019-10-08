#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define PHILS 5
pthread_mutex_t chopsticks[PHILS];
sem_t shared_chops;

void * phil(void * args);
void * semphil(void * args);

int main()
{
	pthread_t tids[PHILS];
	int ids[PHILS];
	void * result;

	//for (int i=0; i<PHILS; i++)
	//	pthread_mutex_init(&chopsticks[i], NULL);
	sem_init(&shared_chops, 0, PHILS/2);

	for (int i=0; i<PHILS; i++)
	{
		ids[i]=i;
		pthread_create(&tids[i], NULL, semphil, &ids[i]);
	}
	for (int i=0; i<PHILS; i++)
	{
		pthread_join(tids[i], &result);
	}
	/*for (int i=0; i<PHILS; i++)
	{
		pthread_mutex_destroy(&chopsticks[i]);
	}*/
	sem_destroy(&shared_chops);
	return 0;
}

void * phil(void * args)
{
	int label = *((int *)args);
	printf("Phil %d is awake\n", label);
	// dijkstra
	int c1 = label;
	int c2 = (label + 1) % PHILS;
	if (c2 < c1)
	{
		c1 = c2;
		c2 = label;
	}
	for (int i=0; i<5; i++)
	{
		pthread_mutex_lock(&chopsticks[c1]);
		usleep(500);
		pthread_mutex_lock(&chopsticks[c2]);
		printf("Phil %d is eating; YUM!\n", label);
		usleep(500);
		pthread_mutex_unlock(&chopsticks[c1]);
		usleep(500);
		pthread_mutex_unlock(&chopsticks[c2]);
		printf("Phil %d is thinking deep thoughts\n", label);
	}
	pthread_exit(NULL);
}

void * semphil(void * args)
{
	int label = *((int *)args);
	printf("Phil %d is awake\n", label);
	for (int i=0; i<5; i++)
	{
		sem_wait(&shared_chops);
		printf("Phil %d is eating; YUM!\n", label);
		usleep(10000000);
		sem_post(&shared_chops);
		printf("Phil %d is thinking deep thoughts\n", label);
	}
	pthread_exit(NULL);
}
