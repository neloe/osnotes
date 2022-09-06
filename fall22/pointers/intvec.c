#include "intvec.h"
#include <stdlib.h>
/*typedef struct _intvec {
    int * m_data;
    int m_cap, m_size;
} intvec;*/
void intvec_init(intvec * vec)
{
    //option 1
    (*vec).m_cap =2;
    // option 2
    vec->m_size = 0;
    vec->m_data = calloc(2, sizeof(int)); 
}
void intvec_push(intvec * vec, int val)
{
    if (vec->m_size == vec->m_cap)
    {
        vec->m_cap *= 2;
        vec->m_data = realloc(vec->m_data, vec->m_cap * sizeof(int));
        /*
        int * temp = vec->m_data;
        vec->m_data = calloc(vec->m_cap, sizeof(int));
        for (int i=0; i<vec->size; i++)
            vec->m_data[i] = temp[i];
        free(temp);
        */
    }
    vec->m_data[vec->m_size] = val;
    vec->m_size++;
}
int intvec_get(intvec vec, int idx, int * val)
{
    if (idx >= vec.m_size || idx < 0) return 0;
    *val = vec.m_data[idx];
    return 1;
}
int intvec_set(intvec vec, int idx, int val)
{
    if (idx >= vec.m_size || idx < 0) return 0;
    vec.m_data[idx] = val;
    return 1;
}
void intvec_free(intvec * vec)
{
    free(vec->m_data);
    vec->m_data = NULL;
    vec->m_cap = 0;
    vec->m_size = 0;
}

int intvec_cap(intvec vec) {return vec.m_cap;}
int intvec_size(intvec vec) {return vec.m_size;}