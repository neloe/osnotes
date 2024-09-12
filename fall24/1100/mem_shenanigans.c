#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=5;
    int * xptr = &x;
    //xptr[1] = 10;
    int * arr = malloc(4*sizeof(int));
    arr[0] = 5;
    arr[1] = 10;
    printf("%d\n", x);
    printf("%d\n", arr[1]);
    return 0;
}
