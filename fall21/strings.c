// strings.c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // "Alice" == {'A', 'l', 'i', 'c', 'e', NULL}
    char name[50];
    scanf("%s", name);
    printf("%s\n", name);
    char * namecpy;
    namecpy = malloc (sizeof(char) * (strlen(name)+1));
    strcpy(namecpy, name);
    printf("%s %s\n", name, namecpy);
    printf("%d\n", strcmp(name, namecpy));
    free(namecpy);
    namecpy = strdup(name);
    printf("%s %s\n", name, namecpy);
    free(namecpy);
    return 0;
}
