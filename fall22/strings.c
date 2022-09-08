#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    printf("Length of arg: %ld\n", strlen(argv[1]));
    char* mystr = malloc((strlen(argv[1])+1) * sizeof(char));
    strcpy(mystr, argv[1]);
    printf("%s, %s\n", mystr, argv[1]);
    return 0;
}
