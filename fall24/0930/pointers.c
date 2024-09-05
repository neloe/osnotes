#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int x = 5;
    int y = 10;
    int *xptr;
    xptr = &x;

    printf("sizeof int: %lu\n", sizeof(int));
    printf("sizeof int*: %lu\n", sizeof(int*));
    printf("x: %d, addr of x: 0x%X\n", x, &x); // &x means address of x
    printf("y: %d, addr of y: 0x%X\n", y, &y); // &x means address of y
    printf("xptr: 0x%X, *xptr: %d, addr of xptr: 0x%X\n", xptr, *xptr, &xptr);

    *xptr = 20;
    printf("*xptr: %d, x: %d\n", *xptr, x);

    int *intarr;
    intarr = malloc(sizeof(int) * 5);
    printf("what's at index 0? %d\n", intarr[0]); // intarr + sizeof(int)*0
    printf("what's at index 1? %d\n", intarr[1]); // intarr + sizeof(int)*1

    printf("xptr[0]: %d\n", xptr[0]);
    printf("xptr[1]: %d\n", xptr[1]);
    int i=0;
    while(1)
    {
        printf("xptr[%d] = %d\n", i, xptr[i]);
        i+=1;
    }
    return 0;
}
