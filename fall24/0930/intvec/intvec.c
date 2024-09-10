#include "intvec.h"
#include <stdlib.h>

int intvec_init(intvec * vec)
{
    // dereferencing option 1
    (*vec).num_elts = 0;
    // dereferencing option 2
    vec->capacity = 2;
    vec->data = calloc(2, sizeof(int));
    if (vec->data) return 1;
    return 0;
}

int intvec_set(intvec vec, size_t idx, int val)
{
    if (idx >= vec.num_elts)
        return 0;
    vec.data[idx] = val;
    return 1;
}

int intvec_get(intvec vec, size_t idx, int * val)
{
    if (idx >= vec.num_elts)
        return 0;
    *val = vec.data[idx];
    return 1;
}

int intvec_add(intvec * vec, int val)
{
    if (vec->num_elts == vec->capacity)
    {
        int * tmp = realloc(vec->data, vec->capacity*2*sizeof(int));
        if (tmp == NULL)
            return 0;
        vec->data = tmp;
        vec->capacity *= 2;
    }
    vec->data[vec->num_elts] = val;
    vec->num_elts += 1;
    return 1;
}

void intvec_free(intvec * vec)
{
    free(vec->data);
    vec->data = NULL;
}
