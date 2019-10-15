#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	//char * cmd [] = {"ls", "-alh", NULL};
	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);
	execvp(argv[1], &argv[1]);
	printf("Hooray!\n");
	return 0;
}
