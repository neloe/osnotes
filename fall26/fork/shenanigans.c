#include <stdio.h>

int main()
{
  int x = 0;
  int y = 1;
  int * xptr = &x;
  int * yptr = &y;
  printf("x: %d, xptr: %x, &xptr: %x\n", x, xptr, &xptr);
  printf("y: %d, yptr: %x, &yptr: %x\n", y, yptr, &yptr);
  printf("%x\n", *(xptr - 2));
  /*
  *yptr = 10;
  printf("x: %d, y: %d\n", x, y);
  *(xptr + 1) = 50;
  printf("x: %d, y: %d\n", x, y);
  *(yptr - 1) = 6;
  printf("x: %d, y: %d\n", x, y);
  *(xptr + 2) += 16;
  printf("x: %d, xptr: %x, &xptr: %x\n", x, xptr, &xptr);
  *xptr = 1234;
  printf("y: %d, yptr: %x, &yptr: %x\n", y, yptr, &yptr);
  printf("x: %d, y: %d\n", x, y);
  *yptr = 10;
  */
  return 0;
}
