/*
 * Single linked list API
 * Author: Max Guerrero
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "dbg.h"
#include "linked_lists.h"

void *SafeMalloc(size_t size)
{
   void *vp;
   if((vp = malloc(size)) == NULL){
      fprintf(stderr, "Out of memory\n");
      return NULL;
   }
   return vp;
}

status CreateList(List **list)
{
   List *new_list = (List *)SafeMalloc(sizeof(List));
   if(!new_list)
      return FAIL;
   new_list->head = NULL;
   new_list->tail = NULL;
   new_list->size = 0;
   *list = new_list;
   return OK;
}

NODE *insertInBeginning(NODE *start, int data) {
   NODE *newNode = SafeMalloc(sizeof(NODE));
   newNode->value = data;
   newNode->next = start;
   return newNode;
}

NODE *removeNode(NODE *start, int data) {
   // special case: delete first node
   NODE *ptr = start;
   NODE *temp = NULL;
   debug("we're alive still");
   if(ptr->value == data)
   {
      temp = start;
      start = temp->next;
      free(temp);
      debug("new start ptr value %d", start->value);
      return start;     
   }

   while((ptr->next)->value != data && ptr->next != NULL)
   {
	   //printf("hey\n");
      ptr = ptr->next;
      debug("current pointer value: %d", ptr->value);
   }

   if(ptr->next != NULL)
   {
      debug("node found, deleting");
      temp = ptr->next;
      ptr->next = temp->next;
      free(temp);
      return start;
   }
   else
   {
      printf("pointer not found\n");
      return start;
   }
}

void insertAtEnd(List *list, NODE *crtNode, int data)
{
   while(crtNode->next != NULL){
      crtNode = crtNode->next;
   }
   NODE *newNode = SafeMalloc(sizeof(NODE));
   newNode->value = data;
   newNode->next = NULL;
   crtNode->next = newNode;
   list->tail = newNode;
}

status appendAtEnd(List *list, int value)
{
   if (list->size == 0)
   {
      list->head = insertInBeginning(list->head, value);
      list->tail = list->head; // for the special case that we created a new list
      return OK; 
   }
   else
   {
      insertAtEnd(list, list->head, value);
      return OK;
   }
}

NODE *reverseList(NODE *start)
{
   NODE *prev, *next, *ptr;
   ptr = start;

   next = ptr->next;
   prev = ptr;
   ptr->next = NULL;
   ptr = next;
  
   while(ptr->next != NULL)
   {
      next = ptr->next;
      ptr->next = prev;
      prev = ptr;
      ptr = next;
   }
   ptr->next = prev;
   start = ptr;

   return start;
}

void printList(NODE *crtNode){
   int count = 1;
   while(crtNode->next != NULL) {
      printf("Value at node %d: %d\n", count, crtNode->value);
      crtNode = crtNode->next;
      count++;
   }
   printf("Value at node %d: %d\n", count, crtNode->value);
}

