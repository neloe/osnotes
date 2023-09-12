#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    // argc: number of command line args
    // argv: the command line args
    for (int i=0; i<argc; i++)
	printf("%s\n", argv[i]);

    printf("%ld\n", strlen(argv[0]));
    int i=5;
    char name[] = {'b','o','b'};
    char n2[] = "asdf";
    printf("%c\n", name[3]);
    printf("%ld\n", strlen(name));
    char * name2 = name;
    printf("%p, %p\n", name, name2);
    name[1] = 'a';
    printf("%s, %s\n", name, name2);
    //copying strings
    char * namecpy = malloc(strlen(name)+1);
    strcpy(namecpy, name);
    printf("%s\n", namecpy);
    free(namecpy);
    return 0;
}
