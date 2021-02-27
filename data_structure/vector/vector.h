#ifndef __VECTOR_H_
#define __VECTOR_H_
#include<stdbool.h>

typedef int vec_type;

struct vector {
	vec_type* data;
	unsigned long lenth;
	unsigned long capacity;
	unsigned long end_addr;
};

typedef struct vector Vector;


bool vec_empty(const Vector);
bool vec_full(const Vector);
void vec_push_back(Vector*, const vec_type);
vec_type vec_pop_back(Vector*);

#endif /* end of __VECTOR_H_*/
