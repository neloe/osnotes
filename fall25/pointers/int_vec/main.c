#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "intvec.h"

int main()
{
  intvec my_vec;
  intvec_init(&my_vec);

  intvec_push(&my_vec, 1);
  int myvalue;
  if(intvec_get(&my_vec, 0, &myvalue) == 1)
  {
    printf("Value is %d\n", myvalue);
  }
  else
  {
    // if we're here, we're absolutely screwed
    // handle an error somehow?
  }
  intvec_set(&my_vec, 0, 5);
  //you really *should* check for errors
  intvec_get(&my_vec, 0, &myvalue);
  printf("Value is %d\n", myvalue);

  intvec_free(&my_vec);

  char * word = strdup("hello");
  printf("%s\n", word);
  free(word);

  return 0;
}
