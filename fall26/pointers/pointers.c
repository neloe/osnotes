#include <stdio.h>
#include <stdlib.h>

void swap (int * a, int * b);

int main()
{
  int x = 5;
  int * xptr;
  int arr [] = {1,2,3,4}; // int [4]
  int arr2 [10]; // size needs to be known at compile time
  arr2[4] = 15;
  /* this is too limiting, let's put an array on the heap
   * similar to "new" in Java
   */
  int * darr = malloc(4 * sizeof(int));
  darr[0] = 5; // darr + 0 * sizeof(int)
  darr[1] = 6; // darr + 1 * sizeof(int)
  free(darr);
  //memory leak!
  // need more space
  darr = calloc(8, sizeof(int));
  free(darr);

  printf("x is %d, addr of x is 0x%x\n", x, &x);
  xptr = &x;
  printf("x is %d, addr of x is 0x%x\n", x, xptr);
  *xptr = 10; // dereference, or follow the pointer
  printf("x is %d, addr of x is 0x%x\n", x, xptr);
  int y = 3;
  printf("x is %d, y is %d\n", x, y);
  swap(&x, &y);
  printf("x is %d, y is %d\n", x, y);
  return 0;
}

void swap (int * a, int * b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
