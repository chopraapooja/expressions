#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_isSpecialSymbol_should_return_1_if_given_symbol_is_specailSymbol,test_isSpecialSymbol_should_return_0_if_given_symbol_is_NOT_specailSymbol,test_getTokens_of_2_plus_3_should_give_TokenList_containing_2_plus_and_3,test_getTokens_test_with_string_containing_rich_set_of_tokans,test_getTokens_test_with_string_containing_spaces,test_isDigit_should_give_0_when_given_char_is_not_numericDigit,test_isDigit_should_give_1_when_given_char_is_numericDigit,test_countDigits_should_give_number_of_digits_in_integer,test_charToString_should_cast_character_to_string,test_charToString_should_return_string_of_length_1_except_NULL_case,test_substr_should_give_substr_of_String_S_of_length_L,test_precedence_of_different_operators,test_ListToString_should_convert_list_of_strings_into_single_string,test_ListToString_should_give_null_on_providing_empty_list;
Test test[] = {"test_isSpecialSymbol_should_return_1_if_given_symbol_is_specailSymbol",test_isSpecialSymbol_should_return_1_if_given_symbol_is_specailSymbol,"test_isSpecialSymbol_should_return_0_if_given_symbol_is_NOT_specailSymbol",test_isSpecialSymbol_should_return_0_if_given_symbol_is_NOT_specailSymbol,"test_getTokens_of_2_plus_3_should_give_TokenList_containing_2_plus_and_3",test_getTokens_of_2_plus_3_should_give_TokenList_containing_2_plus_and_3,"test_getTokens_test_with_string_containing_rich_set_of_tokans",test_getTokens_test_with_string_containing_rich_set_of_tokans,"test_getTokens_test_with_string_containing_spaces",test_getTokens_test_with_string_containing_spaces,"test_isDigit_should_give_0_when_given_char_is_not_numericDigit",test_isDigit_should_give_0_when_given_char_is_not_numericDigit,"test_isDigit_should_give_1_when_given_char_is_numericDigit",test_isDigit_should_give_1_when_given_char_is_numericDigit,"test_countDigits_should_give_number_of_digits_in_integer",test_countDigits_should_give_number_of_digits_in_integer,"test_charToString_should_cast_character_to_string",test_charToString_should_cast_character_to_string,"test_charToString_should_return_string_of_length_1_except_NULL_case",test_charToString_should_return_string_of_length_1_except_NULL_case,"test_substr_should_give_substr_of_String_S_of_length_L",test_substr_should_give_substr_of_String_S_of_length_L,"test_precedence_of_different_operators",test_precedence_of_different_operators,"test_ListToString_should_convert_list_of_strings_into_single_string",test_ListToString_should_convert_list_of_strings_into_single_string,"test_ListToString_should_give_null_on_providing_empty_list",test_ListToString_should_give_null_on_providing_empty_list};
char testFileName[] = {"expressionsTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}