#include "intvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[])
{
    srand(time(NULL));
    intvec iv;
    int val;
    intvec_init(&iv);
    for (int i=0; i<5; i++)
        intvec_push(&iv, rand() % 100);
    for (int i=0; i<intvec_size(iv); i++)
    {
        intvec_get(iv, i, &val);
        printf("%d ", val);
    }
    printf("\n");
    // oops
    intvec_free(&iv);
    return 0;
}