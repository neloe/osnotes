#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char mesg [12] = "Hello world!";
    char mesg2 [3] = "cat";
    // char mesg [] = {'H','e',.....
    strcpy(mesg2, mesg);
    printf("%s, %ld, %ld\n", mesg, strlen(mesg), sizeof(mesg));
    printf("%s, %ld, %ld\n", mesg2, strlen(mesg2), sizeof(mesg2));
    return 0;
}
