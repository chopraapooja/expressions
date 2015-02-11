#include <assert.h>
#include <stdlib.h>
#include "linkedList.h"
#include "expressions.h"

typedef char* String;

void test_isSpecialSymbol_should_return_1_if_given_symbol_is_specailSymbol() {
	assert(isSpecialSymbol('+') == 1);
	assert(isSpecialSymbol('^') == 1);
}
void test_isSpecialSymbol_should_return_0_if_given_symbol_is_NOT_specailSymbol() {
	assert(isSpecialSymbol('NULL') == 0);
	assert(isSpecialSymbol('1') == 0);
	assert(isSpecialSymbol('a') == 0);
	assert(isSpecialSymbol('A') == 0);
}

void test_getTokens_of_2_plus_3_should_give_TokenList_containing_2_plus_and_3() {
	char expr[] = "2+3";
	LinkedList tokens = getTokens(expr);

	assert(tokens.count == 3);

	assert(strcmp((String)getElementAt(tokens, 0), "2") == 0);	
	assert(strcmp((String)getElementAt(tokens, 1), "+") == 0);	
	assert(strcmp((String)getElementAt(tokens, 2), "3") == 0);	
}

void test_getTokens_test_with_string_containing_rich_set_of_tokans() {
	char expr[] = "(2+3)+[14*(665+35)]/0";
	char *expected[] = {"(", "2", "+", "3", ")", "+", "[", "14", "*", "(", "665", "+", "35", ")", "]", "/", "0"};
	LinkedList tokens = getTokens(expr);
	int i;

	assert(tokens.count == 17);
	for (i = 0; i < tokens.count; ++i) {
		assert(strcmp((String)getElementAt(tokens, i), expected[i]) == 0);	
	}
}


void test_getTokens_test_with_string_containing_spaces() {
	char expr[] = "(2+3) + 4  -";
	char *expected[] = {"(","2","+","3",")","+","4","-"};
	LinkedList tokens = getTokens(expr);
	int i;

	assert(tokens.count == 8);	
	for (i = 0; i < tokens.count; ++i) {
		assert(strcmp((String)getElementAt(tokens, i), expected[i]) == 0);	
	}
}

void test_isDigit_should_give_0_when_given_char_is_not_numericDigit() {
	assert(isDigit('a') == 0);
	assert(isDigit('+') == 0);
	assert(isDigit('A') == 0);
	assert(isDigit('@') == 0);
	assert(isDigit('\0') == 0);
}

void test_isDigit_should_give_1_when_given_char_is_numericDigit() {
	int i; char digits[] = {'0','1','2','3','4','5','6','7','8','9'};
	for (i = 0; i < 10; ++i) {
		assert(isDigit(digits[i]) == 1);
	}
}

void test_countDigits_should_give_number_of_digits_in_integer() {
	assert(countDigits(123) == 3);
	assert(countDigits(0) == 1);
	assert(countDigits(-1) == 1);
	assert(countDigits(-123) == 3);
}

void test_charToString_should_cast_character_to_string() {
	String str = charToString('a');
	assert(str[0] == 'a');
	assert(str[1] == NULL);

	str = charToString(NULL);	
	assert(str[0] == NULL);

	str = charToString('1');	
	assert(str[0] == '1');
}

void test_charToString_should_return_string_of_length_1_except_NULL_case() {
	String str = charToString('a');
	assert(strlen(str) == 1);
	str = charToString(NULL);;
	assert(strlen(str) == 0);
}

void test_substr_should_give_substr_of_String_S_of_length_L() {
	String s = "abcdefgh";
	assert(strcmp(substr(s, 2), "ab") == 0);
	assert(strcmp(substr(s, 1), "a") == 0);
	assert(strcmp(substr(s, strlen(s)), s) == 0);
}

void test_precedence_of_different_operators() {
	assert(precedence("^") == 10);
	assert(precedence("*") == 9);
	assert(precedence("/") == 9);
	assert(precedence("+") == 8);
	assert(precedence("-") == 8);
	assert(precedence("(") == 7);
	assert(precedence(")") == 6);
	assert(precedence(NULL) == 0);
}

void test_ListToString_should_convert_list_of_strings_into_single_string() {
	LinkedList names = createList();
	_add_to_list(&names, "Pooja");
	_add_to_list(&names, "Gagan");
	_add_to_list(&names, "Neha");
	assert(strcmp(listToString(names), "Pooja Gagan Neha") == 0);
}

void test_ListToString_should_give_null_on_providing_empty_list() {
	LinkedList names = createList();
	assert(listToString(names) == NULL);
}

// void test_infixToPostfix_should_convert_2_3_plus_to_2_plus_3() {
// 	String infix = "2 +   3";
// 	String postfix = "2 3 +";
// 	assert(strcmp(infixToPostfix(infix), postfix) == 0);
// }

// void test_infixToPostfix_should_convert_infixExpr_to_postfixExpr() {
// 	String infix = "(2+3)*14-2";
// 	String postfix = "2 3 + 14 * 2 -";
// 	assert(strcmp(infixToPostfix(infix), postfix) == 0);
// }

// void test_infixToPostfix_should_handle_expressions_having_multiple_braces() {
// 	String infix = "((2+3)*5)/7^3";
// 	String postfix = "2 3 + 5 * 7 3 ^ /";
// 	assert(strcmp(infixToPostfix(infix), postfix) == 0);
// }

// void test_infixToPostfix_special_cases() {
// 	String infix1 = "(((2+3+4)))"; 
// 	String infix2 = "2+3+4";
// 	String postfix = "2 3 + 4 +";
// 	assert(strcmp(infixToPostfix(infix1), postfix) == 0); 
// 	// assert(strcmp(infixToPostfix(infix2), postfix) == 0); 
// }
