#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void suck_at_baseball(int sig);

int main()
{
    int cpid = fork();
    if (cpid > 0)
    {
	sleep(1);
	while (1)
	{
	    kill(cpid, SIGUSR1);
	    sleep(1);
	}
    }
    else
    {
	signal(SIGUSR1, suck_at_baseball);
	while(1);
    }
    return 0;
}

void suck_at_baseball(int sig)
{
    static int strike = 0;
    static int out = 0;
    strike += 1;
    printf("Strike %d\n", strike);
    if (strike == 3)
    {
	printf ("YER OUT\n");
	strike = 0;
	out += 1;
    }
    if (out == 3)
    {
	kill(getppid(), SIGINT);
	exit(1);
    }
}
