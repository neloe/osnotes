#include "intvec.h"
#include <stdlib.h>

void intvec_init(intvec * iv)
{
  // dereference and dot
  (*iv).m_size = 0;
  // arrow operator
  iv->m_cap = 2;
  iv->m_data = malloc(iv->m_cap*sizeof(int));
}

void intvec_push(intvec * iv, int value)
{
  if (iv->m_size == iv->m_cap)
  {
    iv->m_data = realloc(iv->m_data, iv->m_cap*sizeof(int)*2);
    iv->m_cap *= 2;
  }
  // if strings, use something like strcpy
  iv->m_data[iv->m_size] = value;
  iv->m_size += 1;
}

int intvec_get(const intvec* iv, unsigned int idx, int * val)
{
  if (idx >= iv->m_size) return 0;
  *val = iv->m_data[idx];
  return 1;
}

int intvec_set(intvec* iv, unsigned int idx, int val)
{
  if (idx >= iv->m_size) return 0;
  iv->m_data[idx] = val;
  return 1;
}

void intvec_free(intvec * iv)
{
  free(iv->m_data);
  iv->m_data = NULL;
  iv->m_size = 0;
  iv->m_cap = 0;
}

