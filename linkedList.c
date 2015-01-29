#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList createList(void){
	LinkedList list = {NULL,NULL,0};
	return list;
}

Node * create_node(void *data){
	Node * newNode = NULL;

	newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int add_to_list(LinkedList *list,Node *node){
	if(list->head==NULL){
		list->head = node;
	}
	list->tail = node;
	list->count++;
	return 1;
}

void *get_first_element(LinkedList list){
	return list.head->data;	
}

void *get_last_element(LinkedList list){
	return list.tail->data;
}

void traverse(LinkedList list, void (*func)(void* data)) {
	Node* walker = list.head;
	while(walker!=NULL){
		func(walker->data);
		walker = walker->next;
	}
}