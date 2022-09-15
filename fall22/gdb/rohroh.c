#include <stdlib.h>
#include <stdio.h>

void bar()
{
    int * ptr = NULL;
    * ptr = 10;
}
void foo()
{
    int a = 10;
    int c = 3;
    bar();
}

int main()
{
    int a = 5;
    printf("%d\n", a);
    int b = 10;
    int * ptr;
    foo();
    //*ptr = 8;
    int ** ptrptr = &ptr;
    *ptr = 8;
    *ptrptr = &b;
    *(*ptrptr) = 12;
    return 0;
}
