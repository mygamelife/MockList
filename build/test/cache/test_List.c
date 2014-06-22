#include "unity.h"
#include "List.h"
#include "ErrorCode.h"
#include "CException.h"




List *list;



void setUp(void)

{

 list = ListNew(4);

}



void tearDown(void)

{

}



void test_ListNew(void)

{

 if ((((list->buffer)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)20);;};

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((list->size)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((list->length)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}



void test_listAdd_given_4_2_should_add_4_2(void)

{

 listAdd(list , 4);

 listAdd(list , 2);

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((list->buffer[0])), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((list->buffer[1])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);



 ListDel(list);

}



void test_listIsFull_given_6_7_8_9_10_should_throw_exception(void)

{

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  listAdd(list , 6);

  listAdd(list , 7);

  listAdd(list , 8);

  listAdd(list , 9);

  listAdd(list , 10);

  UnityFail( ("Should throw ERROR_LIST_FULL exception"), (_U_UINT)46);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERROR_LIST_FULL)), (_U_SINT)((err)), ("Expect ERROR_LIST_FULL exception"), (_U_UINT)50, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((list->size)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

 }





}



void test_listRemove_given_11_12_should_remove_11_and_remain_1_size(void)

{

 listAdd(list , 11);

 listAdd(list , 12);

 UnityAssertEqualNumber((_U_SINT)((11)), (_U_SINT)((listRemove(list))), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((list->size)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 ListDel(list);

}



void test_listRemove_given_13_14_should_Remove_13_14_and_throw_exception(void)

{

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  listAdd(list , 13);

  listAdd(list , 14);



  UnityAssertEqualNumber((_U_SINT)((13)), (_U_SINT)((listRemove(list))), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((listRemove(list))), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

  UnityFail( ("Should throw ERROR_LIST_EMPTY exception"), (_U_UINT)77);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERROR_LIST_EMPTY)), (_U_SINT)((err)), ("Expect ERROR_LIST_EMPTY exception"), (_U_UINT)81, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((list->size)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

 }



 ListDel(list);

}
