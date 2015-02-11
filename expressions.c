#include "linkedlist.h"
#include "expressions.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
char* charToString(char ch) ;
char* infixToPostfix(char *expression) ;
char* listToString(LinkedList list) ;
char* substr(char* str, int length) ;
int countDigits(int number) ;
int inRange(int from, int to, char ch) ;
int isDigit(char ch) ;
int isSpecialSymbol(char symbol);
int precedence(char* operator) ;
int* extractNumber(char *expr) ;
LinkedList getTokens(char* expr) ;
void emptyStack(Stack *stack, LinkedList *list) ;
void handleOperator(char* oprator, Stack *stack);
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
}












		
  
