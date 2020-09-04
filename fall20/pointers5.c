#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x = 5;
	printf("%d\n", sizeof(int));
	int * ptr;
	printf("%d\n", sizeof(int *));
	ptr = &x;
	printf("%x\n", ptr);
	printf("%d %d\n", x, *ptr);
	*ptr = 8;
	printf("%d %d\n", x, *ptr);

	int arr[5] = {};

	int * dynarr = malloc(10 * sizeof(int));
	dynarr[0] = 5;
	dynarr[1] = 7;
	printf("%d %d\n", dynarr[0], dynarr[1]);
	printf("%d\n", *dynarr);
	free(dynarr);

	char ** strlist = malloc(10 * sizeof(char*));
	for (int i=0; i<10; i++)
		strlist[i] = malloc(20*sizeof(char));
	strcpy(strlist[0], "hello");
	printf("%s\n", strlist[0]);

	for (int i=0; i<10; i++)
		free(strlist[i]);
	free(strlist);
	return 0;
}
