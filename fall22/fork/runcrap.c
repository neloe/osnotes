#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
    int cpid = fork();
    if (cpid == 0)
    {
	char* args [] = {"git", "add","*.c", 0};
	execvp("git", args);
    }
    else
    {
	sleep(1);
	cpid = fork();
	if (cpid == 0)
	{
	    char* args [] = {"git", "commit","-m","'push from code'", 0};
	    execvp("git", args);
	}
	else
	{
	    sleep(1);

	    cpid = fork();
	    if (cpid == 0)
	    {
		char* args [] = {"git", "push",0};
		execvp("git", args);
	    }
	}
    }
    sleep(10);
    printf("Hello world, I'm alive\n");
    return 0;
}
