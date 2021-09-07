// main.c
#include <stdio.h>
#include "intvec.h"

int main(int argc, char* argv[])
{
    intvec myvec;
    iv_init(&myvec);
    for (int i=0; i<10; i++)
	iv_push(&myvec, i);
    // int val = iv_get(myvec, 0);//nope
    int value;
    for (int i=10; i>=0; i--)
    {
	if (iv_get(myvec, i, &value))
	    printf("%d ", value);
	else
	    printf("Invalid index: %d\n",i);
    }
    for (int i=0; i<10; i++)
    {
	iv_get(myvec, i, &value);
	if (value % 2 == 0)
	    iv_set(myvec, i, -value);
    }
    for (int i=0; i<10; i++)
    {
	iv_get(myvec, i , &value);
	printf("%d ", value);
    }
    printf("\n");

    iv_free(&myvec);
    return 0;
}
