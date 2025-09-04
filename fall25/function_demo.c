#include <stdio.h>
#include <stdlib.h>

int x;// global variable. BAD. SUPER BAD
const int X = 5; // constant.  GOOD.  SUPER GOOD

void foo(int anum);

int main(int argc, char* argv[])
{
  int x;
  int local_var = 15;
  x = 190;
  foo(7);
  return 0;
}

void foo(int anum)
{
  printf("Your number is %d\n", anum);
  printf("x is %d\n", x);
}

