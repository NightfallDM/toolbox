#include<stdio.h>
#include"list.h"
#include<stdbool.h>
#include<stdlib.h>

void list_init(List* listp){
	listp->head = NULL;
	listp->tail = NULL;
	listp->length = 0;
}

void list_release(List* listp){
	Node* temp_nodep = listp->head;
	for (int i=0;i<listp->length - 1;i++){
		listp->head = temp_nodep->next;
		free(temp_nodep);
		temp_nodep = listp->head;
	}
	free(temp_nodep);
	listp->head = NULL;
	listp->tail = NULL;
	listp->length = 0;
}

bool list_empty(const List list){
	return list.length == 0;
}

unsigned int list_length(const List list){
	return list.length;
}

list_type list_get(const List list, unsigned int index){
	Node* temp_nodep = list.head;
	if (index >= list.length){
		return (list_type)-1;
	}
	for (int i=0;i<index;i++){
		temp_nodep = temp_nodep->next;
	}
	return temp_nodep->next->data;
}

void list_insert(List* listp, unsigned int index, list_type val){
	Node* temp_nodep = listp->head;
	if(index >= listp->length -1){
		Node* new_nodep = (Node*)malloc(sizeof(Node));
		new_nodep->data = val;
		new_nodep->next = NULL;
		listp->tail->next = new_nodep;
		listp->tail = new_nodep;
	}else{
		for (int i=0;i<index;i++){
			temp_nodep = temp_nodep->next;
		}

		Node* new_nodep = (Node*)malloc(sizeof(Node));
		new_nodep->data = val;
		new_nodep->next = temp_nodep->next;
		temp_nodep->next = new_nodep;
	}
	listp->length += 1;
}

void list_delete(List* listp, unsigned int index){
	Node* temp_nodep = listp->head;
	if(index < listp->length){
		for (int i=0;i<index;i++){
			temp_nodep = temp_nodep->next;
		}
		
		if (index == listp->length -1){
			listp->tail = temp_nodep;
			listp->length -= 1;
			free(temp_nodep->next);
			temp_nodep->next = NULL;
		}else{
			Node* del_nodep = temp_nodep->next;
			temp_nodep->next = del_nodep->next;
			free(del_nodep);
			listp->length -= 1;
		}
	}
}

int list_locate(const List list, list_type val){
	Node* temp_nodep = list.head;
	for (int i=0;i<list.length;i++){
		if (temp_nodep->data == val){
			return i;
		}
	}
	return -1;
}

bool list_exist(const List list, list_type val){
	int ret_num = list_locate(list, val);
	if (ret_num == -1){
		return false;
	}
	return true;
}

