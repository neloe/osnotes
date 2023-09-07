//intvec.c
#include <stdlib.h>
#include "intvec.h"

void intvec_init(intvec * vec)
{
    // method 1: deref and dot
    (*vec).num_elts = 0;
    // option 2: "follow" the pointer
    vec->capacity = 2;
    vec->data = calloc(vec->capacity, sizeof(int));
}
void intvec_push(intvec * vec, int elt)
{
    if (vec->num_elts == vec->capacity)
    {
        // option 1: like java
        /*vec->capacity *= 2;
        int * temp = vec->data;
        vec->data = calloc(vec->capacity, sizeof(int));
        for (int i=0; i < vec->num_elts; i++)
            vec->data[i] = temp[i];
        free(temp);*/
        // option 2: isn't C cool?
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(int));
    }
    vec->data[vec->num_elts] = elt;
    vec->num_elts += 1;
}

int intvec_get(intvec vec, int idx, int * res)
{
    if (idx >= vec.num_elts || idx < 0) return 0;
    *res = vec.data[idx];
    return 1;
}

int intvec_set(intvec vec, int idx, int val)
{
    if (idx >= vec.num_elts || idx < 0) return 0;
    vec.data[idx] = val;
    return 1;
}
void intvec_free(intvec * vec)
{
    free(vec->data);
    vec->data = NULL;
    vec->capacity = 0;
    vec->num_elts = 0;
}