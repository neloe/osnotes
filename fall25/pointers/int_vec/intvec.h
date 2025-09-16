#ifndef INTVEC_H
#define INTVEC_H

typedef struct _iv{
  unsigned int m_size;
  unsigned int m_cap;
  int * m_data;
} intvec;

//
/// \pre: iv has not been previously init'd
///       unless freed
//
void intvec_init(intvec * iv);
void intvec_push(intvec * iv, int value);
int intvec_get(const intvec * iv, unsigned int idx, int * val);
int intvec_set(intvec * iv, unsigned int idx, int val);
void intvec_free(intvec * iv);


#endif
