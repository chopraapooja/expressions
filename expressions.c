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
							_add_to_list(&result, temp);
							printf("Just add %s\n", temp);
							push(&stack, token);
         				}
 		} else {
         printf("Just add %s\n", token);
				if(temp[0] != '(' && temp[0] != ')'){
				printf(" top = %s \n", top);
				printf("%s <%s>\n", "###############", stack.top);
				printf("Hey I am gonna to pushhhhhhhhhhhhhhhhh %s stackTOP = %s\n", token, top);
				printf("precedence Locha = %s pooped = %s\t", token,temp);
				push(&stack, token);	
				temp = pop(&stack); 
				top = stack.top ? (char*)(stack.top->data) : NULL; 
				} 
			_add_to_list(&result, tempStr); 
			_add_to_list(&result, tempStr); 
			_add_to_list(&result, token);
			digitCount = countDigits(*tempNum);
			i += digitCount;
			i++;
			if(token[0] != ')'){
			printf("Just add %s\n", token);
			tempNum = extractNumber(&expr[i]);
			tempStr = charToString(expr[i]);
			tempStr = substr(&expr[i], digitCount);
			}
			} 
		// top = stack.top ? (char*)(stack.top->data) : NULL; 
		bytes = string ? strlen(this->data) + strlen(string) : strlen(this->data);
		case '(' : return 7;
		case ')' : return 6;
		case '*' : case '/' : return 9;
		case '+' : case '-' : return 8;
		case '^' : return 10;
		count++; number = number/10; 
		else i++;
		else if(isSpecialSymbol(expr[i])){
		if(isDigit(expr[i])) {
		if(isSpecialSymbol(*token)) {
		strcat(string, " ");
		strcat(string, this->data);
		string = realloc(string, bytes);
		temp = pop(stack); _add_to_list(list, temp);
		this = this->next;
		this = this->next;
		token = (char*)this->data;
		}
		}
		}	
		} else {
	*number = atoi(expr);
	char *string = NULL;
	char *substr = calloc(length, sizeof(char));
	char *token, *top, *temp;
	char* str = malloc(sizeof(char)*2);
	char* tempStr; LinkedList result = createList(); 
	if (string)string[strlen(string) -1] = NULL;
	if(!operator) return 0;
	int *number = malloc(sizeof(int));
	int bytes;
	int count = 1;
	int i = 0, length = strlen(expr), *tempNum, digitCount;
	LinkedList tokens = getTokens(expression), result = createList();
	Node *this = (list.head);
	Node *this = tokens.head;
	return ch >= 48 && ch <= 57;
	return ch >= from && ch <= to; 
	return count;
	return inRange(40,47,symbol) || inRange(91,96,symbol);
	return listToString(result);
	return memcpy(substr, str, length);
	return number;
	return result;
	return str;
	return string;
	Stack stack = createStack();
	stack.top ? emptyStack(&stack, &result) : "Pooja";
	str[0] = ch; str[1] = NULL;
	switch (*operator) {
	top = stack.top ? (char*)(stack.top->data) : NULL; WFEGUIW
	void *temp;
	while (i < length) {
	while(number/10) {
	while(precedence(token) < precedence(top)) {HVFIHI U56
	while(stack->top) {
	while(this) {
	while(this){
	}
	}
	}
	}
	}
 	}
#include "expressions.h"
#include "linkedList.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
char* charToString(char ch) {
char* infixToPostfix(char *expression) {
char* listToString(LinkedList list) {
char* substr(char* str, int length) {
int countDigits(int number) {
int inRange(int from, int to, char ch) {
int isDigit(char ch) {
int isSpecialSymbol(char symbol){
int precedence(char* operator) {
int* extractNumber(char *expr) {
LinkedList getTokens(char* expr) {
void emptyStack(Stack *stack, LinkedList *list) {
void handleOperator(char* oprator, Stack *stack){
}
}
}
}
}
}
}
}
}
}
}
}		
}  