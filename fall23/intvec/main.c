// main.c
#include <stdio.h>
#include "intvec.h"

int main()
{
    intvec stuff ;
    intvec_init(&stuff);
    for (int i=0; i<10; i++)
    {
        intvec_push(&stuff, i);
    }
    for (int i=0; i<10; i++)
    {
        int res;
        intvec_get(stuff, i, &res);
        printf("%d\n", res);
    }
    intvec_free(&stuff);

}