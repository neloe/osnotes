#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int x = 5;
    int y = 10;

    int *xptr;
    xptr = &x;
    printf("size of int: %lu\n", sizeof(int));
    printf("x: %d, addr of x: 0x%X\n", x, &x);
    printf("y: %d, addr of y: 0x%X\n", y, &y);

    printf("xptr: 0x%X, *xptr: %d, addr of xptr: 0x%X\n", xptr, *xptr, &xptr);

    *xptr = 20;
    printf("*xptr: %d, x: %d\n", *xptr, x);

    int *intarr;
    intarr = malloc(5*sizeof(int));
    printf("arr[0]: %d\n", intarr[0]);// intarr + sizeof(int)*0 bytes;

    printf("%d\n", xptr[0]);
    printf("%d\n", xptr[1]);
    printf("%d\n", *intarr);

    int i = 0;
    while(1)
    {
        printf("xptr[%d]: %d\n", i, xptr[i]);
        xptr[i] = 0;
        i+=1;
    }

    return 0;
}
