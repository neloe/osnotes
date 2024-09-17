#include <stdio.h>

int main()
{
    int * x = NULL;
    for (int i=0; i<1000000; i++)
        //printf("%d %d %d\n", i, i, i);
        puts("hello\n");
    *x = 5;
    return 0;
}
