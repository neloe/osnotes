#include <stdio.h>

void swap(int *x, int *y);

int main()
{
	int * ptr;
	int x = 5;
	int a = 10;
	int b = 15;
	printf("Hello world\n");
	ptr = &x;
	//int ** ptrptr = &ptr;
	printf("%d\n", x);
	printf("%p\n", &x);
	printf("%p\n", ptr); // Notice no &
	//printf("%p\n", &ptr); // Notice &
	//printf("%p\n", ptrptr);
	printf("%d\n", *ptr);
	*ptr = 10;
	printf("%d\n", x);

	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
	//printf("%d\n", *((int*)x));
	
	return 0;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
