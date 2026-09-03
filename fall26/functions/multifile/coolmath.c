/**
 * @brief Math functionality definitions
 * @author Nathan Eloe
 */

#include "coolmath.h"

unsigned int gcd (unsigned int a, unsigned int b)
{
  unsigned int temp;
  while (b > 0)
  {
    temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}

// the #include for coolmath.h is now absolutely required
int dotprod(vec2d a, vec2d b)
{
  return (a.x * b.x) + (a.y * b.y);
}
