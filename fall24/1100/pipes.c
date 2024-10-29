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
		printf("Failed to create pipe\n");
		exit(1);
	}
	cpid = fork();
	if (cpid > 0)
	{
		// parent
		close(pipefd[0]);
		int count = 0;
		signal(SIGINT, parent_handler);
		char buffer[12];
		while(1)
		{
			sleep(1);
			sprintf(buffer, "%d", count);
			count += 1;
			write(pipefd[1], buffer, strlen(buffer)+1);
		}
	}
	else
	{
		close(pipefd[1]);
		signal(SIGINT, child_handler);
		char buffer[12];
		while(1)
		{
			read(pipefd[0], buffer, 12);
			printf("Child read: %s\n", buffer);
		}
	}
}

void parent_handler(int sig)
{
	close(pipefd[1]);
	kill(cpid, SIGINT);
	exit(0);
}

void child_handler(int sig)
{
	close(pipefd[0]);
	exit(0);
}
