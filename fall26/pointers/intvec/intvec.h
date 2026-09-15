/**
 * @brief Declarations for an integer vector
 */
#ifndef INTVEC_H
#define INTVEC_H

#include <stddef.h>

typedef struct {
  size_t num_elts, capacity;
  int * data;
} intvec;

/**
 * @brief Initializes an intvec
 * @pre v has not previously been initialized without being freed
 * @pre v is not NULL
 */
void intvec_init(intvec * self);

void intvec_pushback(intvec * self, const int data);

int intvec_get(intvec self, size_t idx, int * res);
int intvec_set(intvec self, size_t idx, int val);

void intvec_free(intvec * self);

#endif //INTVEC_H
