// intvec.c

#include "intvec.h"
#include <stdlib.h>

void iv_init(intvec * self)
{
    // deref + dot
    (*self).m_size = 0;
    // arrow operator
    self -> m_cap = 2;
    self->m_data = calloc(2, sizeof(int));
}

int iv_get(intvec self, int idx, int * val)
{
    if (idx < 0 || idx >= self.m_size)
	return 0;
    *val = self.m_data[idx];
    return 1;
}

int iv_set(intvec self, int idx, int val)
{
    if (idx < 0 || idx >= self.m_size)
	return 0;
    self.m_data[idx] = val;
    return 1;
}

void iv_push(intvec * self, int val)
{
    if (self->m_size == self->m_cap)
    {
	//dobule capacity
	self->m_cap *= 2;
	self->m_data = realloc(self->m_data,
		sizeof(int) * self->m_cap);
    }
    //hint project 1: strdup(val)
    self->m_data[self->m_size] = val;
    self->m_size ++;
}

void iv_free(intvec * self)
{
    free(self->m_data);
    self->m_data = NULL;
    self->m_cap = 0;
    self->m_size = 0;
}

