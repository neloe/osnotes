#include "intvec.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    intvec myvec;
    int thething;

    intvec_init(&myvec);
    intvec_add(&myvec, 10);
    if (intvec_get(myvec, 0, &thething) != 1)
    {
        // handle the error
    }
    intvec_get(myvec, 1, &thething);
    printf("%d\n", thething);
    intvec_free(&myvec);
    return 0;
}
