//main.c
#include "point4d.h"
#include "dummy.h"
#include <stdio.h>

int main()
{
    struct point4d mypoint;
    mypoint.x = 3.14;
    //point4d origin = {0.,0.,0.,0.};
    point4d origin = {};
    printf("%f\n", mypoint.x);
    printf("%f\n", origin.x);
    printf("%ld\n", sizeof(double));
    print_point4d(origin);
    printf("\n");
    print_point4d(mypoint);
    printf("\n");
    printf("%ld\n", sizeof (point4d));

    // pointers
    int * intptr;
    int x = 5;
    // get the address of x and store it in intptr
    intptr = &x;
    printf("---\n");
    printf("%d %x\n", x, &x);
    printf("%x %d\n", intptr, *intptr);
    return 0;
}
