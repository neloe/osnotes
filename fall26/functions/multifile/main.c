#include <stdio.h>
#include "coolmath.h"

int main()
{
  vec2d v1;
  v1.x = 1;
  v1.y = -3;
  vec2d v2 = {2/*x*/,4/*y*/};
  printf("The gcd of 25 and 10 is %d\n", gcd(25, 10));
  printf("The dot product of the vectors is %d\n", dotprod(v1, v2));
  return 0;
}
