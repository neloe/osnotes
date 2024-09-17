#include <stdio.h>
#include <stdlib.h>

void a();
void b();
void c();
void d();

int main()
{
    a();
    return 0;
}

void a()
{
    b();
}

void b()
{
    c();
}

void c()
{
    int i1 = 5;
    int i2 = 10;
    d();
}

void d()
{
    int * arr = malloc(4*sizeof(int));
    arr[0]=5;
    arr[1]=10;
    int * x = NULL;
    *x = 5;
}
