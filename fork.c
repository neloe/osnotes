#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	printf("Original process: %d, parent PID: %d\n", getpid(), getppid());
	int cpid = fork();
	if (cpid > 0)
	{
		printf("Parent! Dad jokes! My child is: %d\n", cpid);
	}
	else
	{
		printf("I am the child! My PID: %d, Parent PID: %d\n", getpid(), getppid());
	}
	return 0;
}
