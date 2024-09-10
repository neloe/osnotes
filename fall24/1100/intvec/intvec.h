// header guards
#ifndef INTVEC_H
#define INTVEC_H

#include <stdlib.h>

//code goes here

typedef struct intvec
{
    int * data;
    size_t capacity;
    size_t num_elts;
} intvec;

int intvec_init(intvec * vec);
//int intvec_set(struct intvec,...)
int intvec_set(intvec vec, size_t idx, int val);
/*
 * \pre vec must be initialized
 * \post value at specified index is stored in var pointed to by val
 * \return 0 on fail (index out of bounds), 1 on success
*/
int intvec_get(intvec vec, size_t idx, int * val);
int intvec_add(intvec *vec, int val);
void intvec_free(intvec *vec);
//code ends here

#endif // INTVEC_H
