/**
 * @brief Definitions for integer vector
 */
#include "intvec.h"// quotes because 'local' library
#include <stdlib.h>

void intvec_init(intvec * self)
{
  //Option 1
  //|-----| <- intvec
    (*self).num_elts = 0;
  //Option 2
  self->capacity = 4;
  self->data = calloc(self->capacity, sizeof(int)); 
}

void intvec_free(intvec * self)
{
  free(self->data);
  self->data = NULL;
  self->num_elts = 0;
  self->capacity = 0;
}

int intvec_get(intvec self, size_t idx, int * res)
{
  if (idx >= self.num_elts)
    return 0; // index out of bounds
  *res = self.data[idx];
  return 1;
}

int intvec_set(intvec self, size_t idx, int val)
{
  if (idx >= self.num_elts)
    return 0;
  self.data[idx] = val;
  return 1;
}

void intvec_pushback(intvec * self, const int val)
{
  if (self->num_elts == self->capacity)
  {
    // Java/data structures way
    /*
    int * temp = self->data;
    self->data = calloc(self->capacity * 2, sizeof(int));
    // string.h has memcpy; in java we did
    for (int i=0; i<self->num_elts; i++)
    {
      self->data[i] = temp[i]
    }
    free(temp);
    self->capacity *= 2;
    */
    self->capacity *= 2;
    self->data = realloc(self->data, self->capacity * sizeof(int));
  }
  self->data[self->num_elts] = val;
  self->num_elts += 1;
}
