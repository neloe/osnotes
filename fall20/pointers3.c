#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x = 5;
	printf("Size of int: %dB\n", sizeof(int));
	int * ptr = &x;
	printf("Size of int*: %dB\n", sizeof(int*));
	printf("x is: %d\n", x);
	printf("Address of x: %x\n", &x);
	printf("ptr is: %x\n", &x);
	printf("Derefing the ptr: %d\n", *ptr);
	*ptr = 9;
	printf("x is: %d\n", x);

	int arr[10] = {};

	int * dynarr = malloc(5 * sizeof(int));
	dynarr[0] = 10;
	printf("dynarr[0] is: %d\n", dynarr[0]);
	*dynarr = 15;
	printf("dynarr[0] is: %d\n", dynarr[0]);
	free(dynarr);


        char ** strlist = malloc(5 * sizeof(char*));
	for (int i=0; i<5; i++)
		strlist[i] = malloc(10 * sizeof(char));

	strcpy(strlist[0], "hello");
	printf("%s\n", strlist[0]);

	for (int i=0; i<5; i++)
		free(strlist[i]);
	free(strlist);

	return 0;
}
