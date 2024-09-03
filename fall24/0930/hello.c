#include <stdio.h>
int globalvar = 10;// BAD
const int globalconst = 15; // GOODER
const int GLOBAL_CONST = 15; // Best?

void foo(); // signature
int bar(int x);

int main(int argc, char* argv[])
{
    printf("%s\n", argv[-1]);
    int x = 10;
    //int y = x = 15;
    if (6 == x) // (x = 6)
    {
        printf("%d\n", x);
        printf("Do you hate this yet?\n");
    }
    //calls
    foo();
    bar(5);
    bar(-1);
    printf("%d %u %x\n", -1, -1, -1);
    return 0;
}

//Definitions
void foo()
{
    printf("Wheee!\n");
}

int bar(int x)
{
    for (int i=0; i<x; i++)
    {
        printf("%d thing\n", x);
    }
    return 0;
}
