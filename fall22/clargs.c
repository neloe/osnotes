#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    /*int arr[5] = {};
    printf("sizeof arr: %ld\n", sizeof(arr));
    int * otherarr = malloc(20);
    printf("sizeof otherarr: %ld\n", sizeof(otherarr));
    free(otherarr);
    */
    printf("Number of args: %d\n", argc);
    printf("First Argument: %s\n", argv[0]);
    if (argc > 1)
    {
        printf("other arguments: ");
        for (int i=1; i<argc; i++)
            printf("%s ", argv[i]);
        printf("\n");
    }
    return 0;
}
