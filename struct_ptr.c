#include <stdlib.h>
#include <stdio.h>

typedef struct intvec {
	int * vec;
	int size;
	int capacity;
} intvec;

void iv_init(intvec * self);
void iv_cleanup(intvec * self);
void iv_push(intvec * self, int val);
int iv_get(intvec self, int idx, int * val);
int iv_set(intvec self, int idx, int val);

int main()
{
	intvec v;
	iv_init(&v);

	iv_push(&v, 5);
	int result;
	if(iv_get(v, 0, &result))
		printf("Value at index 0: %d\n", result);

	iv_cleanup(&v);
	return 0;
}

void iv_init(intvec * self)
{
	//explicitly dereference pointer, and use .
	(*self).size = 0;
	//use arrow operator (->)
	self -> capacity = 2;
	self -> vec = (int*) calloc(self->capacity, sizeof(int));
}
void iv_cleanup(intvec * self)
{
	if (self->vec)
		free(self->vec);
	self->vec = NULL;
	self->size = 0;
	self->capacity=0;
}

void iv_push(intvec* self, int val)
{
	if (self->size == self->capacity)
	{
		self->capacity *= 2;
		printf("Resizing\n");
		self->vec = (int*)realloc(self->vec, self->capacity * sizeof(int));
	}
	self->vec[self->size] = val;
	self->size+=1;
}
int iv_get(intvec self, int idx, int * val)
{
	if (idx < 0 || idx >= self.size)
		return 0;
	*val = self.vec[idx];
	return 1;
}

// do not strictly need a pointer to self, we never assign to the struct vars
int iv_set(intvec self, int idx, int val)
{
	if (idx < 0 || idx >= self.size)
		return 0;
	self.vec[idx] = val;
	return 1;
}
