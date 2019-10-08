#include <stdio.h>
#include <pthread.h>

void * my_thread(void* args);
int main()
{
	const int THREADS = 3;
	pthread_t tids[THREADS];
	int label[THREADS] ;
	
	void * result;
	//printf("%lu\n", tid);
	for (int i=0; i<THREADS; i++)
	{
		label[i] = i;
		pthread_create(&tids[i], NULL, my_thread, (void *)&label[i]);
	}
	//printf("%lu\n", tid);
	for (int i=0; i<THREADS; i++)
		pthread_join(tids[i], &result);
	printf("All done!\n");
	return 0;
}

void * my_thread(void* args)
{
	int * intarg = (int *)args;
	for (int i=0; i<10; i++)
	{
		printf("Hello World!%d\n", *intarg);
	}
	*intarg = 6;
	pthread_exit(NULL);
}
