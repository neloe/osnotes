#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
	printf("Bad program call\n");
	exit(1);
    }
    long matsize = atol(argv[1]);
    const double ITERS = 100;
    int ** matrix = malloc(matsize * sizeof(int*));
    for (int i=0; i<matsize; i++)
	matrix[i] = malloc(matsize * sizeof(int));

    long start, end;
    start = clock();
    for (int iter = 0; iter < ITERS; iter++)
    {
	for (int i=0; i<matsize; i++)
	    for (int j=0; j<matsize; j++)
		matrix[i][j] = 5;
    }
    end = clock();
    printf("Average time for [i][j]: %f \n", (end - start)/ITERS);
    
    start = clock();
    for (int iter = 0; iter < ITERS; iter++)
    {
	for (int i=0; i<matsize; i++)
	    for (int j=0; j<matsize; j++)
		matrix[j][i] = 5;
    }
    end = clock();
    printf("Average time for [j][i]: %f \n", (end - start)/ITERS);

    for (int i=0; i<matsize; i++)
	free(matrix[i]);
    free(matrix);
}
