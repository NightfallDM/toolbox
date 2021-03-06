#include"vector.h"
#include<stdio.h>

int main(void){
	Vector vec = vec_init(3);
	Vector* vecp = &vec;
	printf("vec empty? : %d\n", vec_empty(vec));
	printf("vec full? : %d\n", vec_full(vec));
	vec_push_back(vecp, 1);
	vec_push_back(vecp, 2);
	vec_push_back(vecp, 3);
	printf("vec.capacity : %lu\n", vec.capacity);
	printf("vec full? : %d\n", vec_full(vec));
	vec_push_back(vecp, 4);
	printf("vec.capacity : %lu\n", vec.capacity);
	vec_type pop_num = vec_pop_back(vecp);
	printf(" pop_num : %d\n", pop_num);
	vec_print(vec, "int");
	vec_insert(vecp, 2, 100);
	printf("insert 100 at index 2\n");
	vec_print(vec, "int");
	vec_delete(vecp, 3);
	printf("delete val at index 3\n");
	vec_print(vec, "int");
	printf("vec length: %lu\n", vec_length(vec));
	printf("vec capacity: %lu\n", vec_capacity(vec));
	vec_release(vecp);

}
