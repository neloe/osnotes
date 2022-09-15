#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
	printf("Need a param\n");
	exit(1);
    }
    printf("Length of arg: %ld\n", strlen(argv[1]));
    //char* mystr = malloc((strlen(argv[1])+1) * sizeof(char));
    //strcpy(mystr, argv[1]);
    char* mystr = strdup(argv[1]);
    printf("%s, %s\n", mystr, argv[1]);
    free(mystr);
    return 0;
}
