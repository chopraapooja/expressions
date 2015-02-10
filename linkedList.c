#include <stdlib.h>
#include "linkedList.h"

#define DONE 1

void printList(LinkedList list) {
	Node *this = (list.head);
	while(this){
		printf("\"%s\", ", (this->data));
		this = this->next;
	}
}

Node* create_node(void *data) {
	Node *n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

LinkedList createList(void) {
	LinkedList list;
	list.head = NULL;
	list.tail = NULL;
	list.count = 0;
	return list;
}

int add_to_list(LinkedList *list,Node *node) {
	if(!node) return 0;
	if(list->tail == NULL) {
		list->head = node;
		list->tail = node;
	} else{
		list->tail->next = node;
		list->tail = node;
	}
	list->count++; 
	return DONE;
}

int _add_to_list(LinkedList *list, void *data) {
	Node *node = create_node(data);
	add_to_list(list, node);
}

void* get_first_element(LinkedList list) {
	if(!list.head) return NULL;
	return list.head->data;
}

void* get_last_element(LinkedList list) {
	if(!list.head) return NULL;
	return list.tail->data;
}

int parseInt(void *ref){
	return *(int*)(ref);
}

char* parseString(void *ref){
	return *(char**)(ref);
}

// void traverse(LinkedList list, void (*operation)(void *data)) {
// 	Node *walker = list.head;
// 	while(!walker){	operation(walker->data); }
// }

void* getElementAt(LinkedList list, int index) {
	Node *walker = list.head;
	int i;
	if(index >= list.count || index < 0) return NULL;
	for (i = 1; i <= index; ++i) {
		walker = walker->next;
	}
	return walker->data;
}

int indexOf(LinkedList list, void *element) {
	// Node *walker = list.head;
	// int i;
	// while(!walker) {
	// 	walker->data
	// }
}

Node* getNodeAt(LinkedList list, int index){
	Node *walker = list.head; int i;
	if(index < 0 || index >= list.count) return NULL;
	for (i = 1; i <= index; ++i) {
		walker = walker->next;
	}
	return walker;	
}

int asArray(LinkedList list, void **result) {
	int i; 
	Node *this;
	void **r = malloc(list.count);
	for(i=0; i<list.count; ++i){
		this = getNodeAt(list,i);
		r[i] = this->data;
	}
	*result = r;
	return list.count;
}

void* deleteElementAt(LinkedList *list, int index) {
	Node *prev, *next, *this;
	prev = getNodeAt(*list, index-1);
	next = getNodeAt(*list, index+1);
	this = getNodeAt(*list, index);
	if(!this) return NULL;

	if(list->head == this){
		list->head = next;
	}
	if(list->tail == this){
		list->tail = prev;
	}
	if(index > 0 && index < list->count){
		this->next = NULL;
		prev->next = next;
	}
	return this->data;
}

LinkedList* filter(LinkedList list, Predicate predicate) {
	int i; Node *this; LinkedList *filteredList = malloc(sizeof(LinkedList));
	for (i = 0; i < list.count; ++i) {
		this = getNodeAt(list,i);
		if(predicate(this->data)) {
			add_to_list(filteredList, this);
		}
	}
	return filteredList;
}