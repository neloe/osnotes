#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int pipefd[2];
int cpid;
void parent_handler(int sig);
void child_handler(int sig);

int main()
{
	if (pipe(pipefd) == -1)
	{
		printf("Everything is on fire!");
		exit(1);
	}
	cpid = fork();
	if (cpid > 0)
	{
		//parent
		signal(SIGINT, parent_handler);
		int count = 0;
		char buffer[12];
		close(pipefd[0]);
		while(1)
		{
			sprintf(buffer, "%d", count);
			count += 1;
			write(pipefd[1], buffer, strlen(buffer)+1);
			sleep(1);
		}
	}
	else
	{
		signal(SIGINT, child_handler);
		char buffer[12];
		close(pipefd[1]);
		while(1)
		{
			read(pipefd[0], buffer, 12);
			printf("Child got: %s\n", buffer);
		}
	}
}
void parent_handler(int sig)
{
	close(pipefd[1]);
	kill(cpid, SIGINT);
	exit(1);
}

void child_handler(int sig)
{
	close(pipefd[0]);
	exit(1);
}
