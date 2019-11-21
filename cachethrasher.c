#include <time.h>
#include <stdio.h>
#include <stdlib.h>

const int ITERS=10;

int main(int argc, char* argv[])
{
	int probsize = atoi(argv[1]);
	int ** mat = malloc(probsize * sizeof(int*));
	for (int i=0; i<probsize; i++)
		mat[i] = malloc(probsize * sizeof(int));

	clock_t start = clock();
	for (int iter = 0; iter < ITERS; iter++)
	{
		for (int i=0; i<probsize; i++)
			for (int j=0; j<probsize; j++)
				mat[i][j] = 42;
	}
	clock_t end = clock();
	printf("Time elapsed ([i][j]): %f\n", (float)(end-start) / CLOCKS_PER_SEC);

	start = clock();
	for (int iter = 0; iter < ITERS; iter++)
	{
		for (int i=0; i<probsize; i++)
			for (int j=0; j<probsize; j++)
				mat[j][i] = 13;
	}
	end = clock();
	printf("Time elapsed ([j][i]): %f\n", (float)(end-start) / CLOCKS_PER_SEC);

	for (int i=0; i<probsize; i++)
		free(mat[i]);
	free(mat);
}
