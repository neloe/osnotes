#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int x = 5;
	printf("Size of int: %d\n", sizeof(int));
	printf("x is: %d\n", x);

	int * ptr;
	printf("Size of ptr: %d\n", sizeof(int *));
	ptr = &x;
	printf("ptr is: %x\n", ptr);
	printf("Dereferencing ptr: %d\n", *ptr);
	*ptr = 15;
	printf("x is: %d\n", x);
	
	int arr[5] = {};

	int * dynarr = malloc(10 * sizeof(int));
	printf("dynarr: %x\n", dynarr);
	dynarr[0] = 10;
	dynarr[1] = 12;
	printf("%d %d\n", dynarr[0], dynarr[1]);
	printf("*dynarr is: %d\n", *dynarr);
	free(dynarr);

	char ** strlist = malloc( 5 * sizeof(char*));
	for(int i=0; i<5; i++)
		strlist[i] = malloc(10 * sizeof(char));
	strcpy(strlist[0], "hello");
	printf("%s\n", strlist[0]);
	printf("%c\n", **strlist);
	printf("%s\n", *strlist);
	printf("%x\n", *strlist);

	for (int i=0; i<5; i++)
		free(strlist[i]);
	free(strlist);

	printf("Enter a size: ");
	int num;
	//scanf("%d", &num);


	int * userarr = malloc(num * sizeof(int));
	free(userarr);

	unsigned int ui = -1;
	printf("%u\n", ui + 1);




	return 0;
}

