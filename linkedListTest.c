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

void test_add_to_list_adds_an_integer_data_element_to_the_existing_linklist(){
	int c = 9,d = 10;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(int *)(*(list.head)).data,9);
	assertEqual(*(int *)(*(list.tail)).data,10);
}

void test_add_to_list_adds_an_integer_data_element_to_the_empty_character_linklist() {
	char c = 'A';
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(char *)(*(list.head)).data,'A');
}

void test_add_to_list_adds_a_character_data_element_to_the_existing_character_linklist() {
	char c = 'A',d = 'B';
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(char *)(*(list.head)).data,'A');
	assertEqual(*(char *)(*(list.tail)).data,'B');
}

void test_add_to_list_adds_a_string_data_element_to_the_empty_linklist_for_strings() {
	string c = "Ananthu";
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(string *)(*(list.head)).data,"Ananthu");
	assertEqual(*(string *)(*(list.tail)).data,"Ananthu");
}

void test_add_to_list_adds_a_string_data_element_to_the_existing_linklist_for_string() {

	string c = "Ananthu",d = "awesome";
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(string *)(*(list.head)).data,"Ananthu");
}

void test_add_to_list_adds_a_float_data_element_to_the_empty_linklist_for_floats() {
	float c = 72.3;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(float *)(*(list.head)).data,(float)72.3);
	assertEqual(*(float *)(*(list.tail)).data,(float)72.3);
}

void test_add_to_list_adds_a_float_data_element_to_the_existing_float_linklist() {
	float c = 72.3,d = 65.3;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(float *)(*(list.head)).data,(float)72.3);
	assertEqual(*(float *)(*(list.tail)).data,(float)65.3);
}

void test_add_to_list_adds_a_long_int_data_element_to_the_empty_linklist_for_long_ints() {
	long int c = 2147483647;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(long int *)(*(list.head)).data,2147483647);
	assertEqual(*(long int *)(*(list.tail)).data,2147483647);
}

void test_add_to_list_adds_a_long_int_data_element_to_the_existing_long_int_linklist() {
	long int c = 2147483647,d = 2147483646;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(long int *)(*(list.head)).data,2147483647);
	assertEqual(*(long int *)(*(list.tail)).data,2147483646);
}

void test_add_to_list_adds_a_double_data_element_to_the_empty_linklist_for_doubles() {
	double c = 21.1;
	LinkedList list = createList();
	Node *charNode = create_node(&c);
	add_to_list(&list,charNode);
	assertEqual(*(double *)(*(list.head)).data,(double)21.1);
	assertEqual(*(double *)(*(list.tail)).data,(double)21.1);
}

void test_add_to_list_adds_a_double_data_element_to_the_existing_double_linklist() {
	double c = 21.1,d = 21.2;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual(*(double *)(*(list.head)).data,(double)21.1);
	assertEqual(*(double *)(*(list.tail)).data,(double)21.2);
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

void test_traverse_traverse_through_a_int_node_one_by_one() {
	int data = 9;
	LinkedList list = createList();
	Node *intNode = create_node(&data);
	add_to_list(&list,intNode);
	traverse(list,add);
	assertEqual(*(int*)(*(Node*)(list.head)).data, 10);
}

void test_getElementAt_getElementAt_gives_the_data_at_given_position_for_integer() {
	int a = 9,b = 10,c=11;
	LinkedList list = createList();
	Node *node1 = create_node(&a),*node2 = create_node(&b),*node3 = create_node(&c);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);

	assertEqual(*((int*)getElementAt(list,0)),9);
	assertEqual(*((int*)getElementAt(list,1)),10);
	assertEqual(*((int*)getElementAt(list,2)),11);

}

void test_indexOf_indexOf_gives_the_position_of_the_given_element_in_an_integer_linkedlist() {
	int c = 9,d = 10;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	assertEqual((int)((int *)indexOf(list,&c)),0);
	assertEqual((int)((int *)indexOf(list,&d)),1);
}

void test_deleteElementAt_deleteElementAt_deletes_the_element_at_the_given_position() {
	int c = 9,d = 10,e = 11;
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d),*node3 = create_node(&e);
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	assertEqual((int)((int *)indexOf(list,&e)),2);
	deleteElementAt(&list,1);
	assertEqual((int)((int *)indexOf(list,&e)),1);
}

void test_asArray_populates_an_array_with_the_reference_to_data_in_the_list() {
	int c = 9, d = 10, e = 11, count,*data[5];
	LinkedList list = createList();
	Node *node1 = create_node(&c),*node2 = create_node(&d),*node3 = create_node(&e);
	
	add_to_list(&list,node1);
	add_to_list(&list,node2);
	add_to_list(&list,node3);
	count=asArray(list,(void**)data);

	assertEqual(count, 3);
	assertEqual(*(data[0]),9);
	assertEqual(*(data[1]),10);
	assertEqual(*(data[2]),11);
}