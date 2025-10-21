#include <stdio.h>

int main()
{
  printf("Hello stdout\n");
  fprintf(stdout, "Hello stdout 2\n");
  fprintf(stderr, "Hello stderr\n");
  return 0;
}
