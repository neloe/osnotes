//point.c
#include "point4d.h"
#include <stdio.h>

void print_point4d(const point4d pt)
{
    printf("[%f, %f, %f, %f]", pt.x, pt.y, pt.z, pt.w);
}
