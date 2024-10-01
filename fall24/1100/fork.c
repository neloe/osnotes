#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    //printf("How many times does this print (before fork)\n");
    int cpid = fork();
    if (cpid == 0)
    {
        ////printf("Am child, my PID: %d, parent PID: %d\n", getpid(), getppid());
        srand(getpid());
        for (int i=0; i<10; i++)
            printf("%d ", rand()%100);
        printf("\n");
    }
    else
    {
        ////printf("In parent, my PID: %d, child PID: %d\n", getpid(), cpid);
        srand(getpid());
        for (int i=0; i<10; i++)
            printf("%d ", rand()%100);
        printf("\n");
    }
    //printf("How many times does this print (after fork)\n");
    return 0;
}
