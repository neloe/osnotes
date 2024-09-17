#include <stdio.h>

int main()
{
    int * x = NULL;
    int start = 0;
    for (int i=0; i<100000; i++)
    {
        //start ++;
        printf("%d %d %d", i, i, i);
        //fflush(stdout);
    }
    *x = 5;
    return 0;
}
