//point4d.h
#ifndef POINT4D_H
#define POINT4D_H

typedef struct point4d
{
    float x,y,z,w;
} point4d;


void print_point4d(const point4d pt);
#endif
