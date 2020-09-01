#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x = 5;
	printf("%d\n", x);
	printf("%u\n", sizeof(x));
	int * ptr = &x;
	printf("%u\n", ptr);
	printf("%d\n", *ptr);
	int arr[5] = {};
	double * darr = malloc(10 * sizeof(double));
	darr[0] = 3.14;
	printf("%f\n", darr[0]);
	free(darr);

	char ** strings = malloc (5 * sizeof(char*));
	for (int i=0; i<5; i++)
		strings[i] = malloc(10 * sizeof(char));
	strcpy(strings[0], "hello");
	printf("%s\n", strings[0]);
	printf("%s\n", *strings);
	for (int i=0; i<5; i++)
		free(strings[i]);
	free(strings);
	return 0;
}
