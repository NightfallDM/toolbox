#ifndef __LIST_H_
#define __LIST_H_
#include<stdbool.h>

typedef int list_type;

typedef struct node {
	list_type data;
	struct node* next;
}Node;

struct list {
	Node* head;
	Node* tail;
	unsigned int length;	
};

typedef struct list List;

void list_init(List*);
void list_release(List*);
void list_clear(List*);
bool list_empty(const List);
unsigned int list_length(const List);
list_type list_get(const List, unsigned int);
void list_insert(List*, unsigned int, list_type);
void list_delete(List*, unsigned int);
bool list_exist(const List, list_type);
int list_locate(const List, list_type);

#endif /* end of __LIST_H_ */
