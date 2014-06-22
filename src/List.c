#include "List.h"
#include "ErrorCode.h"
#include "malloc.h"
#include "stdio.h"
#include "CException.h"

List *ListNew(int length)
{
	List *ListCreate = malloc(sizeof(List));
	ListCreate->buffer = malloc(sizeof(int) * length);
	ListCreate->size = 0;
	ListCreate->length = length;
}

void listAdd(List *list , int data)
{	
	list->buffer[list->size] = data;
	list->size++;
	if(listIsFull(list))
		Throw(ERROR_LIST_FULL);
}

int listIsFull(List *list)
{
	if(list->size > list->length)
		return 1;
		
	else return 0;
}

void ListDel(List *list)
{
	free(list->buffer);
	free(list);
}

int listRemove(List *list)
{
	int RemovedData;
	
	
	RemovedData = *list->buffer;
	list->size--;	
	list->buffer++;	
			
	if(listIsEmpty(list))
		Throw(ERROR_LIST_EMPTY);
		
	return RemovedData;
}

int listIsEmpty(List *list)
{
	if(list->size == 0)
		return 1;
		
	else return 0;	
}