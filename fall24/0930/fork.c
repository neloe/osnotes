#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main()
{
    printf("How many times will this print?\n");
    int cpid = fork();
    if (cpid > 0)
    {
    srand(getpid());
        //        printf("I am the parent, child PID: %d, my PID: %d, my parent: %d\n", cpid, getpid(), getppid());
        for (int i=0; i<10; i++)
        {
            printf("%d ", rand()% 100);
        }
        printf("\n");
    }
    else
    {
    srand(getpid());
        for (int i=0; i<10; i++)
        {
            printf("%d ", rand()% 100);
        }
        printf("\n");
    }

    //        printf("Am child, my PID: %d, my parent PID: %d\n", getpid(), getppid());
    //printf("This should print twice\n");
    return 0;
}
