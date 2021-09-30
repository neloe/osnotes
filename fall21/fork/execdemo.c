#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main()
{
    int x = 5;
    int cpid;
    cpid = fork();
    if (cpid > 0)
    {
	printf("I'm in the parent, childpid is %d\n", cpid);
	sleep(10);
    }
    else if (cpid == 0)
    {
	char* args [] = {"ls", "-alh", NULL};
	execvp("ls", args);
    }
    return 0;
}
