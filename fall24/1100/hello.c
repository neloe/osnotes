#include <stdio.h>

int global_var = 5; // BAD
const int global_const = 15; // GOODER
const int GLOBAL_CONST = 16; // GOODEST

void foo();
int bar(int x);

int main(int argc, char* argv[])
{
    int x = 10;
    //int y = x = 15;
    if (6 == x) //(x = 6)
    {
        printf("%d\n", x);
    }
    printf("Hello world!\n");
    printf("%s\n", argv[0]);
    printf("%d %u 0x%x\n", -1, -1, -1);
    foo();
    bar(5);
    bar(-1);
    return 0;
}

void foo()
{
    printf("in foo\n");
}

int bar(int x)
{
    for (int i=0; i<x; i++)
    {
        printf("%d yay\n", i);
    }
    return 5;
}
