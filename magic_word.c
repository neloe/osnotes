#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handler(int sig);

int main()
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);
	while(1);
	return 0;
}

void handler(int sig)
{
	printf("Ah ah ah, you didn't say the magic word!\n");
}
