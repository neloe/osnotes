#ifndef INTVEC_H
#define INTVEC_H

typedef struct intvec{
    int * m_data;
    int m_size; // number of elements
    int m_cap; // capacity
} intvec;

// note: might cause memleaks if self has
// been initialized and not freed
void iv_init(intvec * self);
// pre: self must be initialized
int iv_get(intvec self, int idx, int * val);
// pre: self must be initialized
int iv_set(intvec self, int idx, int val);
// pre: self must be initialized
void iv_push(intvec * self, int val);
// pre: self must be initialized
void iv_free(intvec * self);

#endif
