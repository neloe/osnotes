//main.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#include "func.h"
// NEVER INCLUDE A .C
//#include "func.c"
// returns a random number x: low <= x < high
//int randint(int low, int high);

int main()
{
    srand(time(NULL));
    printf("%d\n", randint(1,10));
    return 0;
}

/*int randint(int low, int high)
{
    return rand() % (high - low) + low;
}*/


