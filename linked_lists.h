#ifndef LINKED_LISTS
#define LINKED_LISTS

typedef struct Node {
   int value;
   struct Node *next;
}NODE;

typedef struct {
   NODE *head;
   NODE *tail;
   int  size;   
} List;


typedef enum
{
  FAIL,
  OK
} status;

void *SafeMalloc(size_t size);
status CreateList(List **list);
status appendAtEnd(List *list, int value);
NODE *insertInBeginning(NODE *start, int data);
void insertAtEnd(List *list, NODE *crtNode, int data);
void printList(NODE *crtNode);
NODE *removeNode(NODE *start, int data);
NODE *reverseList(NODE *start);

#endif
