#include "stack.h"
#include <stdlib.h>


Stack createStack(void) {
	Stack s = {NULL,NULL};
	return s;
}
S_Node* createNode(void *data) {
	S_Node *n = malloc(sizeof(S_Node));
	n->data = data;
	n->back = NULL;
	return n;
}

int push(Stack *stack, void *element) {
	S_Node *node = create_node(element, 2);
	node->back = stack->top;
	stack->top = node;
	return ++(stack->height);
}

void printStack(Stack stack) {
	S_Node *this = (stack.top);
	while(this){
		printf("|%c|\n", *(char*)(this->data));
		this = this->back;
	}
}

void * pop(Stack *stack) {
	void *element; S_Node *prev;
	if(!stack->top) return NULL;
	prev = stack->top;
	element = stack->top->data;
	stack->top = stack->top->back;
	free(prev);
	return element;
}