// header guards
#ifndef INTVEC_H
#define INTVEC_H
#include <stdlib.h>
// code goes here
typedef struct intvec {
    int * data;
    size_t capacity;
    size_t num_elts;
} intvec;

int intvec_init(intvec *vec);
//int intvec_set(struct intvec
int intvec_set(intvec vec, size_t idx, int val);

/*
 * \pre vec has been initialized
 * \post var pointed to by val constains the value at the idx
 * \return 1 on success, 0 on failure (index out of bounds)
*/
int intvec_get(intvec vec, size_t idx, int *val);
int intvec_add(intvec *vec, int val);
void intvec_free(intvec *vec);
// code stops here

#endif // INTVEC_H
