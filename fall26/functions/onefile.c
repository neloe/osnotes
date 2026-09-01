/**
 * @brief Demo of single file functions
 * @author Nathan Eloe
 */

#include <stdio.h>
#include <limits.h>

// function signature/prototype/declaration
// thing we need # 1
/**
 * @brief Calculates the greatest common denominator
 * @param a a number
 * @param b another number
NOT NEEDED, COMPILER ENFORCES// * @pre a >= 0, b >=0
 * @return gcd of the two values
 * required function comments: brief, param/return (when applicable)
 */
unsigned int gcd(unsigned int a, unsigned int b);

int main(int argc, char* argv[])
{
  int x;
  puts("Hello world");
  x = gcd(10, 5); // thing # 3: function call
  printf("GCD of 10 and 5 is %d\n", x);
  puts("Fun with types");
  /*printf("sizeof int: %d\n", sizeof(int));
  printf("INT_MAX: %d\n", INT_MAX);
  printf("sizeof long: %d\n", sizeof(long));
  printf("ULONG_MAX: %lu\n", ULONG_MAX);
  printf("sizeof float: %d\n", sizeof(float));
  printf("sizeof double: %d\n", sizeof(double));
  printf("-1 as an unsigned integer: %lu\n", -1);
  printf("UINT_MAX: %ld\n", UINT_MAX);
  */
  return 0;
}

// Thing we need #2
// function definition
unsigned int gcd(unsigned int a, unsigned int b)
{
  unsigned int temp;
  while (b!=0)
  {
    temp = b;
    b = a%b;
    a = temp;
  }
  return a;
}
