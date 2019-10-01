#include <stdio.h>
#include <pthread.h>

void * my_thread(void* args);
int main()
{

	pthread_t tid;
	int label = 1;
	void * result;
	printf("%lu\n", tid);
	pthread_create(&tid, NULL, my_thread, (void *)&label);
	printf("%lu\n", tid);
	pthread_join(tid, &result);
	printf("All done!%d\n", label);
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
