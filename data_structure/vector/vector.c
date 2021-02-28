#include<stdlib.h>
#include"vector.h"

Vector vec_init(int cnt){
	Vector vec = {
			.data = malloc(cnt * sizeof(vec_type)),
			.lenth = 0,
			.capacity = cnt,
			};
	return vec;

}

bool vec_empty(const Vector vec){
	return vec.lenth == 0;
}

bool vec_full(const Vector vec){
	return vec.lenth == vec.capacity;
}

void vec_push_back(Vector* vecp, const vec_type val){
	if (vec_full(*vecp)){
		vecp->data = (vec_type*)realloc(vecp->data, vecp->capacity * sizeof(vec_type));
		vecp->capacity *= 2;
		vec_push_back(vecp, val);
	}else{
		(vecp->data)[vecp->lenth] = val;
		vecp->lenth += 1;
	}

}

vec_type vec_pop_back(Vector* vecp){
	if (vec_empty(*vecp))
		return (vec_type)(-1);
	vecp->lenth -= 1;
	return (vecp->data)[vecp->lenth];
}
