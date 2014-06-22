#include "Storage.h"
#include "stdio.h"
#include "malloc.h"
#include "List.h" 

void store(List *list , int value[] , int length)
{
	int i=0;
	
	for(i ; i<length ; i++)
	{
	
		if(!listIsFull(list))
		{
			listAdd(list, value[i]);
		}
	}
}

int *retrieve(List *list , int *size)
{	
	int i = 0 ;
	int CountSize = 0;
	int *Storage;
	
	Storage = malloc(sizeof(int) * (*size));
	
	while(!listIsEmpty(list))
	{
		Storage[i++] = listRemove(list);
		CountSize++;
	}
	
	*size = CountSize;
	
	return Storage;
}