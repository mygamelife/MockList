





typedef struct

{

 int *buffer;

 int size;

 int length;

}List;



List *ListNew(int length);

void listAdd(List *list , int data);

void ListDel(List *list);

int listRemove(List *list);

int listIsEmpty(List *list);

int listIsFull(List *list);
