#include "intvec.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    intvec myvec;
    int thething;

    intvec_init(&myvec);
    intvec_add(&myvec, 10);
    intvec_get(myvec, 0, &thething);

    return 0;
}
