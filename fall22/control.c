#include <stdio.h>

// functions
// part 1: function prototype
// return type, name, param types
void print_square(int side_size);

int global_variable = 10; // DO NOT DO THISs
			  // global variables bad

int main()
{
	int x;
	x = 5;
	if/*while*/ (x == 5)
		printf("Universe still exists, %d == 5\n", x);
	// part 3: function call
	print_square(x);
	printf("x is %d\n", x);
	return 0;
}

// part 2: function definition
void print_square(int side_size)
{
	for (int i=0; i<side_size; i++)
		printf("_");
	printf("\n");
	for (int i=0; i<side_size; i++)
	{
		printf("|");
		for (int j=0; j<side_size-2; j++)
			printf(" ");
		printf("|\n");
	}
	for (int i=0; i<side_size; i++)
		printf("_");
	printf("\n");
	printf("side size and increment: %d ", side_size);
	side_size++;
	printf("%d\n", side_size);
	return;
}
