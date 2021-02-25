// !!! fail do not use
#include<stdio.h>
#include"test.h"

int main(void){
//typedef int Node;
#define Node int
	struct abc abc_int = {1, 2, 3};
	printf("abc_int :[%d, %d, %d]\n", abc_int.a, abc_int.b, abc_int.c);

//typedef float Node;
#define Node float
	struct abc abc_float = {1.1, 2.2, 3.3};
	printf("abc_float :[%f, %f, %f]\n", abc_float.a, abc_float.b, abc_float.c);

	return 0;
}
