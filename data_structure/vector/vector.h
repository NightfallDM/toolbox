#ifndef __VECTOR_H_
#define __VECTOR_H_
#include<stdbool.h>

typedef int vec_type;

struct vector {
	vec_type* data;
	unsigned long length;
	unsigned long capacity;
};

typedef struct vector Vector;


Vector vec_init(int);
bool vec_empty(const Vector);
bool vec_full(const Vector);
void vec_push_back(Vector*, const vec_type);
vec_type vec_pop_back(Vector*);
void vec_clear(Vector*);
void vec_release(Vector*);
void vec_insert(Vector*, unsigned long, vec_type);
void vec_delete(Vector*, unsigned long);
vec_type vec_get(const Vector, unsigned long);
bool vec_exist(const Vector, vec_type);
long vec_locate(const Vector, vec_type);
unsigned long vec_length(const Vector);
unsigned long vec_capacity(const Vector);
void vec_print(const Vector, char*);

/* ERROR NUMBER */


/* END ERROR NUMBER */

#endif /* end of __VECTOR_H_*/
