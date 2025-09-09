#include <stdlib.h>
#include <stdio.h>

void swap(int * a, int * b);

int main(int argc, char* argv[])
{
  int x;// x is 4B in memory that contains an int
  //double y;
  x = 5;
  printf("x is %d\n", x);
  printf("x is storing its value at address 0x%x\n", &x);
  // &x gives us the memory address of the variable x 
  int * xptr;//, not_a_pointer;
  printf("xptr current value: 0x%x\n", xptr);
  xptr = &x;
  printf("Now, xptr is: 0x%x\n", xptr);
  printf("The value at 0x%x is %d\n", xptr, *xptr);
  *xptr = 15; // go to the addr in xptr, set that to 15
  printf("x is %d, *xptr is %d\n", x, *xptr);

  int y = 20;
  printf("x is %d, y is %d\n", x, y);
  swap(&x, &y);
  printf("x is %d, y is %d\n", x, y);

  int array[] = {1,2,3,4};
  printf("%x, %d\n", array, array[0]); 
  printf("%d\n", *array);
  //printf("%d\n", array[4]);
  //array[4] = 10;
  //printf("%d\n", array[4]);
  int * dyn_array;
  dyn_array = malloc(4 * sizeof(int));
  dyn_array = calloc(4, sizeof(int));

  return 0;
}







void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

