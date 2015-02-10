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

char* listToString(LinkedList list) {
	Node *this = (list.head);
	char *string = NULL;
	int bytes;
	while(this){
		bytes = string ? strlen(this->data) + strlen(string) : strlen(this->data);
		string = realloc(string, bytes);
		strcat(string, this->data);
		strcat(string, " ");
		this = this->next;
	}
	if (string)string[strlen(string) -1] = NULL;
	return string;
}

char* infixToPostfix(char *expression) {
	LinkedList tokens = getTokens(expression), result = createList();
	Node *this = tokens.head;
	Stack stack = createStack();
	char *token, *top, *temp;
	
	while(this) {
		token = (char*)this->data;
		top = stack.top ? (char*)(stack.top->data) : NULL; 

		if(isSpecialSymbol(*token)) {
			while(precedence(token) < precedence(top)) {
				printf("precedence Locha = %s\n", token);
				temp = pop(&stack); 
				if(temp[0] != '(' && temp[0] != ')'){
					printf("Just add %s\n", temp);
					_add_to_list(&result, temp);
				} 
					
				top = stack.top ? (char*)(stack.top->data) : NULL; 
			}
			if(token[0] != ')'){
				printf("Hey I am gonna to pushhhhhhhhhhhhhhhhh %s stackTOP = %s\n", token, top);
				push(&stack, token);	
			} 
		} else {
			printf("Just add %s\n", token);
			_add_to_list(&result, token);
		}	
		this = this->next;
	}
	stack.top ? emptyStack(&stack, &result) : "Pooja";
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

