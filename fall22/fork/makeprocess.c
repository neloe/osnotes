#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    // some code here
    // more code
    int x = 5;
    int y = 10;
    int uninit;
    int cpid = fork();
    srand(getpid());
    if (cpid == 0)
    {
	printf("In the child; x,y,uninit: %d %d %d\n", x, y, uninit);
	printf("Child random number: %d\n", rand()%100);
	printf("Child pid: %d\n", getpid());
    }
    else if (cpid > 0)
    {
	printf("In the parent; x,y,uninit: %d %d %d\n", x, y, uninit);
	printf("Parent random number: %d\n", rand()%100);
	printf("In parent, child pid is: %d\n", cpid);
	printf("Parent pid: %d\n", getpid());
    }
    printf("My parent's PID: %d\n", getppid());
    return 0;

}
