#include <stdio.h>
#include <signal.h>
#include <unistd.h>

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
	static int count = 0;
	count += 1;
	if (count <=3)
		printf("system: ACCESS DENIED\n");
	if (count == 3)
	{
		sleep(1);
		printf("and....\n");
		sleep(1);
	}
	if (count >= 3)
		printf("Ah ah ah, you didn't say the magic word!\n");
}
