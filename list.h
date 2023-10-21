#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"


typedef struct
{
    u8 address[30];
    u8 name[15];
    u8 date_of_birth[12];
    u8 phone_number[12];
    u16 id;
    u16 computer_science_grade;
}student_t;

typedef student_t ListEntry;

typedef struct myNode
{
    ListEntry data;
    struct myNode *pNext;
    struct myNode *pPrev;
}ListNode_t;

typedef struct
{
    ListNode_t *pHead;
    ListNode_t *pTail;
    u32 ListSize;
}List_t;


typedef enum{
	TRUE = 1,
	FALSE = 0
}bool_t;

void List_init(List_t *pl);


void List_insertNode(List_t *pl, ListEntry *e);
void List_deleteNode(List_t *pl, ListEntry *e);
void List_isEmpty(const List_t *pl,bool_t *pstate);
void List_print(const List_t *pl);
void List_listSize(const List_t *pl,u32 *psize);
void List_freeList(List_t *pl);
void List_searchNode(List_t *pl, ListEntry *e, ListNode_t **ppNode);

#endif // LIST_H_INCLUDED
