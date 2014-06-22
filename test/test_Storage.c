#include "unity.h"
#include "Storage.h"
#include "mock_List.h"

#define LENGTH 10
List list;

void setUp(void)
{	
	int listbuffer[10];
	list.buffer = listbuffer;
	list.size = 0;
	list.length = LENGTH;
}

void tearDown(void)
{
}

void test_store_give_1_2_3_should_add_1_2_3(void)
{	
	int integer[] = {1 , 2 , 3};
	
	listIsFull_ExpectAndReturn(&list , 0);
	listAdd_Expect(&list , 1);
	listIsFull_ExpectAndReturn(&list , 0);
	listAdd_Expect(&list , 2);
	listIsFull_ExpectAndReturn(&list , 0);
	listAdd_Expect(&list , 3);
	listIsFull_ExpectAndReturn(&list , 1);
	
	store(&list , integer , 4);	
}

void test_retrieve_given_6_7_8_should_retrieve_6_7_8(void)
{	
	int integer[] = {6 , 7 , 8};
	int i = 0;
	int StoredIntegerSize;
	int *StoredIntegers;
	
	listIsEmpty_ExpectAndReturn(&list , 0);
	listRemove_ExpectAndReturn(&list , 6);
	listIsEmpty_ExpectAndReturn(&list , 0);
	listRemove_ExpectAndReturn(&list , 7);
	listIsEmpty_ExpectAndReturn(&list , 0);
	listRemove_ExpectAndReturn(&list , 8);
	listIsEmpty_ExpectAndReturn(&list , 1);
	
	StoredIntegers = retrieve(&list , &StoredIntegerSize);
	
	for(i ; i < StoredIntegerSize ; i++)
	{
		printf("Stored Integers : %d \n" , StoredIntegers[i]);
	}
}
