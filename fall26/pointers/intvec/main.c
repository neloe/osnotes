/**
 * @brief demo of int vector
 * @author Nathan Eloe
 */

#include "intvec.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
  srand(time(NULL));
  intvec iv;
  intvec_init(&iv);
  printf("RANDMAX: %d\n", RAND_MAX);
  for (int i=0; i<10; i++)
    intvec_pushback(&iv, rand()%100);
  for (int i=0; i<10; i++)
  {
    int val;
    intvec_get(iv, i, &val);
    printf("%d ", val);
  }
  printf("\n");
  intvec_free(&iv);
}

