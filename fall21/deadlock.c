#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// try to demo deadlock
void * thread1fcn(void * args);
void * thread2fcn(void * args);

pthread_mutex_t mut1, mut2;
int data;

int main()
{
    pthread_mutex_init(&mut1, NULL);
    pthread_mutex_init(&mut2, NULL);

    pthread_t th1, th2;
    pthread_create (&th1, NULL, thread1fcn, NULL);
    pthread_create (&th2, NULL, thread2fcn, NULL);

    void * results;
    pthread_join(th1, &results);
    pthread_join(th2, &results);
    return 0;
}

void * thread1fcn(void * args)
{
    for (int i=0; i<10; i++)
	printf("Thread 1: %d\n", i);
    printf("Starting to get keys(1)\n");
    pthread_mutex_lock(&mut1);
    sleep(3);
    pthread_mutex_lock(&mut2);
    printf("I got my mutexes!(1)");
    data += 1;
    pthread_mutex_unlock(&mut1);
    pthread_mutex_unlock(&mut2);
    pthread_exit(NULL);
}
void * thread2fcn(void * args)
{
    for (int i=0; i<10; i++)
	printf("Thread 2: %d\n", i);
    printf("Starting to get keys(2)\n");
    pthread_mutex_lock(&mut2);
    sleep(3);
    pthread_mutex_lock(&mut1);
    printf("I got my mutexes!(2)");
    data / 3;
    pthread_mutex_unlock(&mut1);
    pthread_mutex_unlock(&mut2);
    pthread_exit(NULL);
}
