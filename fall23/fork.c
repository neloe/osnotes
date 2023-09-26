#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// this bad no do
int stuff = 10;

int main(int argc, char* argv[])
{
    int cpid = fork();
    char * cmd[] = {"ls", "-alh", NULL};
    srand(time(NULL)+getpid());
    if (cpid == 0)
    {
	execvp("ls", cmd);
	printf("I'm a child!:%d\n", getpid());
	printf("Child's parent:%d\n", getppid());
	printf("Child rand:%d\n", rand() % 100);
	stuff++;
	printf("Child stuff:%d\n", stuff);
    }
    else
    {
	printf("I'm the parent!:%d\n", cpid);
	printf("Parent PID:%d\n", getpid());
	printf("Parent rand:%d\n", rand() % 100);
	stuff--;
	printf("Parent stuff:%d\n", stuff);
    }
    sleep(1);
    return 0;
}
