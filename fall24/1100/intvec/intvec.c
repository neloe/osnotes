#include "intvec.h"

int intvec_init(intvec * vec)
{
    (*vec).num_elts = 0;
    vec->capacity = 2;
    vec->data = calloc(2, sizeof(int));
    if (vec->data)
        return 1;
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

int intvec_add(intvec *vec, int val)
{
    if (vec->capacity == vec->num_elts)
    {
        int * tmp = realloc(vec->data, sizeof(int) * vec->capacity * 2);
        if (!tmp)
            return 1;
        vec->data = tmp;
        vec->capacity *= 2;
    }
    vec->data[vec->num_elts] = val;
    vec->num_elts += 1;
}

void intvec_free(intvec *vec)
{
    free(vec->data);
    vec->data = NULL;
}









