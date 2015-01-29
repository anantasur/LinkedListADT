#include "linkedlist.h"
#include "expr_assert.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test_create_a_linkedList_returns_head_and_tail_NULL(){
	LinkedList list = createList();
	assertEqual(0,(int)list.head);
	assertEqual(0,(int)list.tail);
	assertEqual(0,((int)list.count));
};

void test_create_a_node_containing_data_10_and_next_as_NULL(){
	int data = 10;
	Node *newNode = create_node((void*)data);

	assertEqual(data,(int)newNode->data);
	assertEqual(0,(int)newNode->next);
	free(newNode);
};

void test_create_a_node_it_contain_data_Ananthu_and_NULL(){
	char* data = "Ananthu";
	Node *newNode = create_node((void*)data);
	char* expData = newNode->data;

	assertEqual(strcmp(expData,data),0);
	assertEqual(0,(int)newNode->next);
	free(newNode);
};

void test_add_to_list_add_the_element_into_list_and_return_1(){
	int id = 23,result;
	LinkedList student = createList();
	Node *expected = create_node((void*)id);

	result = add_to_list(&student,expected);
	assertEqual(result,1);
};

void test_add_to_list_adds_an_integer_data_element_to_the_empty_linklist(){
	int data = 9;
	LinkedList list = createList();
	Node *intNode = create_node(&data);

	add_to_list(&list,intNode);
	assertEqual(*(int *)(*(list.head)).data,9);
}

void test_get_first_element_gives_the_first_element_of_the_link_list() {
	int c = 9,*res;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	res = get_first_element(list);
	assertEqual(*res, 9);
}

void test_get_last_element_gives_the_first_element_of_the_link_list_if_there_is_only_one_element() {	int c = 9,*res;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	res = get_last_element(list);
	assertEqual(*res, 9);
}

void add(void* data) {
	*(int*)data += 1;
}

void test_traverse_traverse_through_a_int_node_and_increases_each_element_by_one() {
	int c = 9;
	LinkedList list = createList();
	Node *intNode = create_node(&c);
	add_to_list(&list,intNode);
	traverse(list,add);
	assertEqual(*(int*)(*(Node*)(list.head)).data, 10);
}