#include <unistd.h>
#include <stdio.h>

int main()
{
    char *args [] = {"ls", "-alh", NULL};
    execvp("ls", args);
    printf("Hello world!\n");
}
