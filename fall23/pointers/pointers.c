#include <stdio.h>

void foo (int *x);
void swap (int *a, int *b);

int main()
{
    //int x = 5;
    // equivalent to
    int x; // declare
    printf("x is %d\n", x);
    x = 5; // initialize
    int * ptr;
    printf("ptr is %p\n", ptr);
    ptr = &x;// & means address of
    printf("ptr is %p, &x is %p\n", ptr, &x);
    printf("val at ptr is %d, x is %d\n", *ptr, x);
    *ptr = 10;
    printf("val at ptr is %d, x is %d\n", *ptr, x);
    foo(&x);
    printf("x is now: %d\n", x);
    int y = 3;
    printf("x: %d, y: %d\n", x, y);
    swap(&x, &y);
    printf("x: %d, y: %d\n", x, y);
    return 0;  
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void foo(int *x)
{
    *x += 1;
    printf("%d\n", *x);
}