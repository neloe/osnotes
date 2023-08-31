//func.c
#include <stdlib.h>
#include "func.h"

int randint(int low, int high)
{
    return rand() % (high - low) + low;
}