#ifndef INTVEC_H
#define INTVEC_H

typedef struct _intvec {
    int * m_data;
    int m_cap, m_size;
} intvec;

// pre: vec must not have been previously init'd
//      without being free'd
void intvec_init(intvec * vec);
// pre: vec must be initialized and not null
void intvec_push(intvec * vec, int val);
// pre: val must have space to store an int
int intvec_get(intvec vec, int idx, int * val);
int intvec_set(intvec vec, int idx, int val);
void intvec_free(intvec * vec);

int intvec_cap(intvec vec);// {return vec.m_cap;}
int intvec_size(intvec vec);// {return vec.m_size;}
// in main:
// struct _intvec stuff;
// intvec stuff2; // are equiv

#endif