#include "stats.h"

double avg(int a, int b)
{
	return (a + b) / 2.0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
