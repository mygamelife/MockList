#include "unity.h"
#include "mock_List.h"
#include "Storage.h"




List list;



void setUp(void)

{

 int listbuffer[10];

 list.buffer = listbuffer;

 list.size = 0;

 list.length = 10;

}



void tearDown(void)

{

}



void test_store_give_1_2_3_should_add_1_2_3(void)

{

 int integer[] = {1 , 2 , 3};



 listIsFull_CMockExpectAndReturn(24, &list, 0);

 listAdd_CMockExpect(25, &list, 1);

 listIsFull_CMockExpectAndReturn(26, &list, 0);

 listAdd_CMockExpect(27, &list, 2);

 listIsFull_CMockExpectAndReturn(28, &list, 0);

 listAdd_CMockExpect(29, &list, 3);

 listIsFull_CMockExpectAndReturn(30, &list, 1);



 store(&list , integer , 4);

}



void test_retrieve_given_6_7_8_should_retrieve_6_7_8(void)

{

 int integer[] = {6 , 7 , 8};

 int i = 0;

 int StoredIntegerSize;

 int *StoredIntegers;



 listIsEmpty_CMockExpectAndReturn(42, &list, 0);

 listRemove_CMockExpectAndReturn(43, &list, 6);

 listIsEmpty_CMockExpectAndReturn(44, &list, 0);

 listRemove_CMockExpectAndReturn(45, &list, 7);

 listIsEmpty_CMockExpectAndReturn(46, &list, 0);

 listRemove_CMockExpectAndReturn(47, &list, 8);

 listIsEmpty_CMockExpectAndReturn(48, &list, 1);



 StoredIntegers = retrieve(&list , &StoredIntegerSize);



 for(i ; i < StoredIntegerSize ; i++)

 {

  printf("Stored Integers : %d \n" , StoredIntegers[i]);

 }

}
