#include "unity.h"
#include "List.h"
#include "ErrorCode.h"
#include "CException.h"

#define LENGTH 4
List *list;

void setUp(void)
{
	list = ListNew(LENGTH);
}

void tearDown(void)
{
}

void test_ListNew(void)
{	
	TEST_ASSERT_NOT_NULL(list->buffer);
	TEST_ASSERT_EQUAL(0 , list->size);
	TEST_ASSERT_EQUAL(LENGTH , list->length);
}

void test_listAdd_given_4_2_should_add_4_2(void)
{
	listAdd(list , 4);
	listAdd(list , 2);
	TEST_ASSERT_EQUAL(4 , list->buffer[0]);
	TEST_ASSERT_EQUAL(2 , list->buffer[1]);
	
	ListDel(list);
}

void test_listIsFull_given_6_7_8_9_10_should_throw_exception(void)
{
	CEXCEPTION_T err;
	
	Try
	{
		listAdd(list , 6);
		listAdd(list , 7);
		listAdd(list , 8);
		listAdd(list , 9);
		listAdd(list , 10);
		TEST_FAIL_MESSAGE("Should throw ERROR_LIST_FULL exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERROR_LIST_FULL , err , "Expect ERROR_LIST_FULL exception");
		TEST_ASSERT_EQUAL(5 , list->size);
	}
	
	
}

void test_listRemove_given_11_12_should_remove_11_and_remain_1_size(void)
{
	listAdd(list , 11);
	listAdd(list , 12);
	TEST_ASSERT_EQUAL(11 , listRemove(list));
	TEST_ASSERT_EQUAL(1 , list->size);
	ListDel(list);
}

void test_listRemove_given_13_14_should_Remove_13_14_and_throw_exception(void)
{
	CEXCEPTION_T err;
	
	Try
	{
		listAdd(list , 13);
		listAdd(list , 14);
	
		TEST_ASSERT_EQUAL(13 , listRemove(list));
		TEST_ASSERT_EQUAL(14 , listRemove(list));
		TEST_FAIL_MESSAGE("Should throw ERROR_LIST_EMPTY exception");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERROR_LIST_EMPTY , err , "Expect ERROR_LIST_EMPTY exception");
		TEST_ASSERT_EQUAL(0 , list->size);		
	}
	
	ListDel(list);
}