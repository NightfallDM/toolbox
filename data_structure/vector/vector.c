#include<stdlib.h>
#include"vector.h"
#include<stdio.h>

Vector vec_init(int cnt){
	Vector vec = {
			.data = malloc(cnt * sizeof(vec_type)),
			.length = 0,
			.capacity = cnt,
			};
	return vec;

}

bool vec_empty(const Vector vec){
	return vec.length == 0;
}

bool vec_full(const Vector vec){
	return vec.length == vec.capacity;
}

static inline void _vec_expand(Vector* vecp){
	unsigned long delt = vecp->capacity;
	vecp->data = (vec_type*)realloc(vecp->data, delt * sizeof(vec_type));
	vecp->capacity += delt;
}

void vec_push_back(Vector* vecp, const vec_type val){
	if (vec_full(*vecp)){
		//vecp->data = (vec_type*)realloc(vecp->data, vecp->capacity * sizeof(vec_type));
		//vecp->capacity *= 2;
		_vec_expand(vecp);
		vec_push_back(vecp, val);
	}else{
		(vecp->data)[vecp->length] = val;
		vecp->length += 1;
	}

}

vec_type vec_pop_back(Vector* vecp){
	if (vec_empty(*vecp))
		return (vec_type)(-1);
	vecp->length -= 1;
	return (vecp->data)[vecp->length];
}

void vec_clear(Vector* vecp){
	vecp->length = 0;
}

void vec_release(Vector* vecp){
	free(vecp->data);
	vecp->length = vecp->capacity = 0;
}

void vec_insert(Vector* vecp, unsigned long index, vec_type val){
	if (index >= vecp->length){
		if (vecp->length == vecp->capacity){
			_vec_expand(vecp);
			vec_push_back(vecp, val);
		}else{
			vec_push_back(vecp, val);
		}
	}else{
		vec_type* temp_valp = vecp->data + vecp->length;
		for (int i=vecp->length-1;i>=index;i--){
			(vecp->data)[i] = *temp_valp;
			temp_valp--;
		}
		(vecp->data)[index] = val;
		vecp->length += 1;
	}
}

void vec_delete(Vector* vecp, unsigned long index){
	if (index >= vecp->length - 1){
		vec_pop_back(vecp);
	}else{
		vec_type* temp_valp = vecp->data + index + 1;
		for (int i=index + 1;i<vecp->length;i++){
			(vecp->data)[i] = *temp_valp;
			temp_valp++;
		}
		vecp->length -= 1;
	}
}

vec_type vec_get(const Vector vec, unsigned long index){
	if (index >= vec.length){
		return vec.data[vec.length - 1];
	}
	return (vec.data)[index];
}

bool vec_exist(const Vector vec, vec_type val){
	if (vec_empty(vec)){
		return false;
	}
	for (int i=0;i<vec.length;i++){
		if ((vec.data)[i] == val){
			return true;
		}
	}
	return false;
}

long vec_locate(const Vector vec, vec_type val){
	if (vec_empty(vec)){
		return -1;
	}
	for (int i=0;i<vec.length;i++){
		if ((vec.data)[i] == val){
			return i;
		}
	}
	return -1;
}

unsigned long vec_length(const Vector vec){
	return vec.length;
}

unsigned long vec_capacity(const Vector vec){
	return vec.capacity;
}

void vec_print(const Vector vec, char* type){
	if (type == "int"){
		printf("[");
		for (int i=0;i<vec.length;i++){
			printf("%d, ", (vec.data)[i]);
		}
		printf("]\n");
	}else if(type == "double" || type == "float"){
		printf("[");
		for (int i=0;i<vec.length;i++){
			printf("%ld, ", (vec.data)[i]);
		}
		printf("]\n");
	
	}
}
