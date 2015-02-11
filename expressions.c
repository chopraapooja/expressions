#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "linkedList.h"
#include "expressions.h"

char* substr(char* str, int length) {
	char *substr = calloc(length, sizeof(char));
	return memcpy(substr, str, length);
} 

int inRange(int from, int to, char ch) {
	return ch >= from && ch <= to; 
}

int isSpecialSymbol(char symbol){
	return inRange(40,47,symbol) || inRange(91,96,symbol);
}

int isDigit(char ch) {
	return ch >= 48 && ch <= 57;
}

char* charToString(char ch) {
	char* str = malloc(sizeof(char)*2);
	str[0] = ch; str[1] = NULL;
	return str;
}

int* extractNumber(char *expr) {
	int *number = malloc(sizeof(int));
	*number = atoi(expr);
	return number;
}

int countDigits(int number) {
	int count = 1;
	while(number/10) {
		count++; number = number/10; 
	}
	return count;
}

int precedence(char* operator) {
	if(!operator) return 0;
	switch (*operator) {
		case '^' : return 10;
		case '*' : case '/' : return 9;
		case '+' : case '-' : return 8;
		case ')' : return 6;
		case '(' : return 7;
 	}
}

char* strcpyheap(char *dest) {
	char *source = malloc(strlen(dest));
	strcpy(source, dest);
	return source;
} 

char* listToString(LinkedList list) {
	Node *this;
	char *string;
	int bytes;
	
	
	if(!list.head) return NULL;
	this = (list.head)->next;
	string = strcpyheap(list.head->data);

	while(this){
		bytes = strlen(this->data) + strlen(string);
		string = realloc(string, bytes);
		strcat(string, " ");
		strcat(string, this->data);
		this = this->next;
	}
	return string;
}

int isBraces(char* token){
	if(!strcmp(token, "(")) return 1;  
	if(!strcmp(token, ")")) return 2;  
	return 0;
}

void* getTop(Stack* stack) {
	return stack->top ? (stack->top->data) : NULL;
}

void handleOperator(char* operator, Stack* stack, LinkedList *list) {
	char *top,*temp;
	top = getTop(stack); 
	while((precedence(operator) <= precedence(top))){
		printf("precedence Locha = %s, top=%s\n", operator,top);
		temp = pop(stack); 
		_add_to_list(list, temp);
		printf("Just add %s\n", temp);
		top = getTop(stack);
	}
	printf("Hey I am gonna to pushhhhhhhhhhhhhhhhh %s stackTOP = %s\n", operator, top);
	push(stack, operator);	
}

char* infixToPostfix(char *expression) {
	LinkedList tokens = getTokens(expression), result = createList();
	Node *this = tokens.head;
	Stack stack = createStack();
	char *token, *top, *temp;
	
	while(this) {
		token = (char*)this->data;
		top = getTop(&stack);

		if(isSpecialSymbol(*token)) {
			if(isBraces(token) == 1){
				printf("Hey I am gonna to pushhhhhhhhhhhhhhhhh %s stackTOP = %s\n", token, top);
				push(&stack, token);
			}
			else if(isBraces(token) == 2) {
				while(isBraces(top) != 1) { 
					printf("POPing = %s\n",top); 
					temp = pop(&stack); 
					printf("Just add %s\n", temp);
					_add_to_list(&result, temp);
					top = getTop(&stack); 
				}
				pop(&stack);	top = getTop(&stack);
			}			
			else {
				handleOperator(token, &stack, &result);
			}
 		} 
		else {
			printf("Just add %s\n", token);
			_add_to_list(&result, token);
		}	
		this = this->next;
	}
	printList(result);	
	printf("******************** top %s\n", top);
	emptyStack(&stack, &result);
	return listToString(result);
}

void emptyStack(Stack *stack, LinkedList *list) {
	void *temp;
	while(stack->top) {
		temp = pop(stack); _add_to_list(list, temp);
	}
}

LinkedList getTokens(char* expr) {
	int i = 0, length = strlen(expr), *tempNum, digitCount;
	char* tempStr; LinkedList result = createList(); 
	while (i < length) {
		if(isDigit(expr[i])) {
			tempNum = extractNumber(&expr[i]);
			digitCount = countDigits(*tempNum);
			tempStr = substr(&expr[i], digitCount);
			_add_to_list(&result, tempStr); 
			i += digitCount;
		}
		else if(isSpecialSymbol(expr[i])){
			tempStr = charToString(expr[i]);
			_add_to_list(&result, tempStr); 
			i++;
		}
		else i++;
	}
	return result;
}		

