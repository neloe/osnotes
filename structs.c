// structs
#include <stdlib.h>
#include <stdio.h>

typedef struct _table {
	double length, width;
	int legs, height;
} table;

struct foo {int a, b, c;};

void print_table_stats(table t);

int main()
{
	table desk;
	desk.length = 5.5;
	desk.width = 1.5;
	desk.legs = 2;
	struct foo bar;
	printf("size of table:%lu\n", sizeof(table));
	printf("size of int:%lu\n", sizeof(int));
	printf("size of long:%lu\n", sizeof(long));
	printf("size of double:%lu\n", sizeof(double));
	double * shenanigans = (double *)(&desk);
	printf("%f\n", shenanigans[0]);
	printf("%f\n", shenanigans[1]);
	printf("%f\n", shenanigans[2]);
	int * more_shen = (int *)(&desk);
	for (int i=0; i<6; i++)
		printf("%d\n", more_shen[i]);
	print_table_stats(desk);
	printf("%lu\n", sizeof(int *));
	printf("%lu\n", sizeof(double *));
	return 0;
}


void print_table_stats(table t)
{
	printf("Length %f, Width %f, Legs %d\n", t.length, t.width, t.legs);
}
