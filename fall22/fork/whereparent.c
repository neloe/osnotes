#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int cpid = fork();
    if (cpid == 0)
    {
	printf("Parent process id: %d\n",getppid());
	sleep(10);
	printf("Parent process id: %d\n",getppid());
	kill(getppid(), SIGKILL);
    }
    else
    {
	printf("My pid: %d\n", getpid());
    }
    if (cpid > 0)
	printf("I'm done, bye\n");
    return 0;
}
