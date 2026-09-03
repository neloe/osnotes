/**
 * @brief math functionality declarations
 * @author Nathan Eloe
 */

// This might work?
//#pragma once

// Header guard
#ifndef COOLMATH_H
#define COOLMATH_H

/*
 * struct vec2d
 * {
 *   int x;
 *   int y;
 * };
 */

typedef struct vec2d
{
  int x;
  int y;
} vec2d;
// -------------
// |  x  |  y  |
// | 4B  | 4B  |
// -------------

// TODO: put function documentation here
unsigned int gcd (unsigned int a, unsigned int b);

// vec2d functions

// the type is struct vec2d
// without the typedef
//int dotprod(struct vec2d a, struct vec2d b);

// with typedef
int dotprod (vec2d a, vec2d b);

#endif //COOLMATH_H
