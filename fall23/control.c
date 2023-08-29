#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// three parts for functions
// part 1: function prototype
// return_type function_name (parameter list);
int rand_between(int a, int b);

int main()
{
    srand(time(NULL));
    int randval;
    for (int i=14; i>0; i-=1)
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
    // part 3: function call
    printf("%d\n", rand_between(1,10));
    return 0; 
}
// part 2: function definition
int rand_between(int a, int b)
{
    return rand() % (b-a) + a;
}
