#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[] = "Hello world!";
	printf("%s\n", str);
	printf("%ld\n", strlen(str));
	char * str2 = (char*) malloc(sizeof(char)*(1+strlen(str)));
	//char str2[10];
	strcpy(str2, str);
	printf("%s\n", str2);
	printf("%s\n", str);

	printf("are they equal?\n");
	printf("%d\n", strcmp(str, str2));
	printf("%d\n", strcmp("Hello", "World"));
	printf("%d\n", strcmp("Hello", "Help"));
	printf("%d\n", strcmp("Hello", "hello"));

	free(str2);

	printf("TOKENIZATION\n");
	char sent[] = "In a hole in the ground there lived a hobbit.";
	char * token;
	printf("%s\n", sent);
	token = strtok(sent, " ");
	while (token!=NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	
	printf("%s\n", sent);
	token = strtok(sent, " ");
	return 0;
}
