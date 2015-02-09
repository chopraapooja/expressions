#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

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

