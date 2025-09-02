// Put name and 
/* description at top
you can use multiline comments
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
  puts("Hello from puts");
  printf("Hello world from printf\n");

  //prior to C99(ish?) had to do this at the top of 
  // the block (the opening { )
  int my_integer = 5;
  int science = 10;
  printf("This is my integer: %d\n",my_integer);
  int a;
  printf("Uninitialized value: %d\n", a);
  printf("Size of an int: %ld\n", sizeof(int));
  if (my_integer == 10)
  //{
    printf("Causality seems to have been violated...\n");
  //}
  if (my_integer = 10)
  {
    printf("This shouldn't show, right? %d\n", my_integer);
  }
  // Yes, you can do this
  // just because you can...
  //int x, y;
  //x = y = 10;
  //while (!(0 == my_integer))
  while(0 != my_integer)
  {
    printf("%d\n", my_integer);
    my_integer -= 1;
  }
}
