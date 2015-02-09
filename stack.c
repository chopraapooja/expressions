#include "stack.h"
#include <stdlib.h>


Stack createStack(void) {
	Stack s = {NULL,NULL};
	return s;
}
Node* create_node(void *data) {
	Node *n = malloc(sizeof(Node));
	n->data = data;
	n->back = NULL;
	return n;
}

int push(Stack *stack, void *element) {
	Node *node = create_node(element);
	node->back = stack->top;
	stack->top = node;
	return ++(stack->height);
}

void printStack(Stack stack) {
	Node *this = (stack.top);
	while(this){
		printf("|%c|\n", *(char*)(this->data));
		this = this->back;
	}
}

void * pop(Stack *stack) {
	void *element; Node *prev;
	if(!stack->top) return NULL;
	prev = stack->top;
	element = stack->top->data;
	stack->top = stack->top->back;
	free(prev);
	return element;
}