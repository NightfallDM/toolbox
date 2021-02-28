#include<stdio.h>
#include<stdlib.h>

int main(void){
	int * num_a = (int*)malloc(30 * sizeof(int));
	printf("&num_a = %lu\n", (unsigned long)num_a);

	int* num_b = (int*)realloc(num_a, 31*sizeof(int));
	printf("&num_b = %lu\n", (unsigned long)num_b);

}
