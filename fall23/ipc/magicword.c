#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
void magicword(int sig);

int main()
{
    signal(SIGINT, magicword);
    while(1);
    return 0;
}

void magicword(int sig)
{
    printf("AH AH AH, YOU DIDN'T SAY THE MAGIC WORD\n");
    // do cleanup code here
    exit(1);
}
