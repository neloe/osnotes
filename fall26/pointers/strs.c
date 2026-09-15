#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  // a string is an array of characters
  char s1[] = "Hello";// ['H', 'e', 'l', 'l', 'o', NULL];
		      // NULL Terminated Character Array (NTCA)
  char* s1cpy = calloc(strlen(s1)-1, sizeof(char));
  strcpy(s1cpy, s1);
  printf("%s \n", s1);
  printf("%s \n", s1cpy);
  printf("%s \n", strdup(s1));
  free(s1cpy);
  return 0;
}
