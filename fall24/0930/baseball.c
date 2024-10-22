#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void hitball(int sig);

int main()
{
	int cpid = fork();
	if (cpid > 0)
	{
		// parent
		sleep(1);
		for (int i=0; i<3; i++)
		{
			printf("Pitching\n");
			kill(cpid, SIGUSR1);
			sleep(1);
		}
		kill(cpid, SIGINT);
	}
	else
	{
		// child
		signal(SIGUSR1, hitball);
		while(1) sleep(1);
	}
	return 0;
}

void hitball(int sig)
{
	static int strikes = 0;
	strikes += 1;
	printf("Steeerike %d\n", strikes);
	if (strikes == 3)
		printf("Yer out!\n");
}
