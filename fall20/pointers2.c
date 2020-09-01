#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int x = 5;
	int * ptr = &x;
	printf("%d\n", sizeof(int));
	printf("%d\n", x);
	printf("%x\n", ptr);
	printf("%x\n", &x);
	printf("%d\n", *ptr);
	char str1[10] = {};
	str1[0] = 'g';
	printf("%s\n", str1);
	int * arr = malloc(20 * sizeof(int));
	arr[0] = 5;
	printf("%d\n", arr[0]);
	printf("%d\n", *arr);
	free(arr);

	char ** strlist = malloc(10*sizeof(char*));
	for (int i=0; i<10; i++)
		strlist[i] = malloc(64*sizeof(char));
	strcpy(strlist[0], "hello world");
	printf("%s\n", strlist[0]);

	for (int i=0; i<10; i++)
		free(strlist[i]);
	free(strlist);
	//free(strlist);
	return 0;
}
