//intvec.h
#ifndef INTVEC_H
#define INTVEC_H

typedef struct intvec {
    int capacity;
    int num_elts;
    int * data;
} intvec;

// struct intvec my_vector; // no more
// intvec my_vector;

/// \pre vec must not be NULL
/// \pre vec should not have been initialized previously unless free'd
/// \post vec initialized with 0 elts and capacity 2
void intvec_init(intvec * vec);

void intvec_push(intvec * vec, int elt);

/// \pre vec, res MUST not be NULL
/// \post *res contains the element at the specified index
/// \return 1 on success, 0 on index out of bounds
int intvec_get(intvec vec, int idx, int * res);
int intvec_set(intvec vec, int idx, int val);

void intvec_free(intvec * vec);

#endif