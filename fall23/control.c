#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int randval;
    for (int i=12; i>0; i-=1)
    {
	if (i%2 == 0)
	    printf("%d\n", i);
    }
    bool ean = true;
    while (ean)
    {
	randval = rand();
	printf("%d\n", randval);
	ean = (randval % 11 == 0);
    }
    return 0; 
}
