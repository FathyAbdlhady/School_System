#include "list.h"
#include "school.h"






void List_init(List_t *pl)
{
    pl->pHead = pl->pTail = NULL;
    pl->ListSize = 0;
}

void List_insertNode(List_t *pl, ListEntry *e)
{
   ListNode_t *pn = (ListNode_t *)malloc(sizeof(ListNode_t));
   if(pn == NULL)
   {
       printf("heap is full\n");
   }
   else
   {
       pn->data = *e;
       pn->pNext = NULL;
       pn->pPrev = NULL;

       bool_t state;
       List_isEmpty(pl,&state);

       if(state == TRUE)
       {
            pl->pHead = pl->pTail = pn;
            (pl->ListSize)++;
       }
       else
       {
           ListNode_t *temp = pl->pHead;
           while( temp != NULL)
           {
               if(temp->data.name[0] < pn->data.name[0])
               {
                   temp = temp->pNext;
               }
               else
               {
                   break;
               }

           }

           if(temp == pl->pHead)
           {
                pn->pNext = pl->pHead;
                pl->pHead->pPrev = pn;
                pl->pHead = pn;
           }
           else if(temp == NULL)
           {
                pl->pTail->pNext = pn;
                pn->pPrev = pl->pTail;
                pl->pTail = pn;
           }
           else
           {
                pn->pNext = temp;
                pn->pPrev = temp->pPrev;
                pn->pPrev->pNext = pn;
                temp->pPrev = pn;

           }
           (pl->ListSize)++;
       }

   }
}

void List_deleteNode(List_t *pl, ListEntry *e)
{
    bool_t state;
    List_isEmpty(pl,&state);

    if(state == TRUE)
    {
        printf("Student is not in the list\n");
    }
    else
    {
        ListNode_t *temp = pl->pHead;
        while( temp != NULL)
        {
            if(temp->data.id != e->id)
            {
                temp = temp->pNext;
            }
            else
            {
                break;
            }
        }

        if( temp == NULL )
        {
            printf("Student is not in the list\n");
        }
        else
        {
            if( (temp == pl->pHead) && (temp == pl->pTail))
            {
                pl->pHead = pl->pTail = NULL;

            }
            else if(temp == pl->pHead)
            {
                pl->pHead = pl->pHead->pNext;
                pl->pHead->pPrev = NULL;
                temp->pNext = NULL;
            }
            else if(temp == pl->pTail)
            {
                pl->pTail = pl->pTail->pPrev;
                pl->pTail->pNext = NULL;
                temp->pPrev = NULL;
            }
            else
            {
                temp->pPrev->pNext = temp->pNext;
                temp->pNext->pPrev = temp->pPrev;
                temp->pNext = temp->pPrev = NULL;
            }
            free(temp);
            (pl->ListSize)--;
            printf("Student is deleted\n");
        }
    }
}

void List_print(const List_t *pl)
{
    bool_t state;
    List_isEmpty(pl,&state);

    if(state == TRUE)
    {
        printf("There are no students\n");
    }
    else
    {
        ListNode_t *temp;
        printf("Students information in alphabetically ascending order\n\n");
        for(temp = pl->pHead; temp != NULL; temp = temp->pNext)
        {
            printf("Student Id = %d\n",temp->data.id);
            printf("Student Name = %s\n",temp->data.name);
            printf("Student Date of birth = %s\n",temp->data.date_of_birth);
            printf("Student Address = %s\n",temp->data.address);
            printf("Student phone_number = %s\n\n",temp->data.phone_number);
        }
    }

}


void List_listSize(const List_t *pl,u32 *psize)
{
    *psize = pl->ListSize;
}

void List_freeList(List_t *pl)
{
    bool_t state;
    List_isEmpty(pl,&state);

    if(state == TRUE)
    {
    }
    else
    {
        ListNode_t *temp = pl->pHead;
        while( temp != NULL)
        {
            temp = temp->pNext;
            free(pl->pHead);
            pl->pHead = temp;
        }
        pl->pTail = NULL;
        pl->ListSize = 0;
    }
}

void List_searchNode(List_t *pl, ListEntry *e, ListNode_t **ppNode)
{
    bool_t state;
    List_isEmpty(pl,&state);

    if(state == TRUE)
    {
        *ppNode = NULL;

    }
    else
    {
        ListNode_t *temp = pl->pHead;
        while( temp != NULL)
        {
            if(temp->data.id != e->id)
            {
                temp = temp->pNext;
            }
            else
            {
                break;
            }
        }

        if( temp == NULL )
        {
            *ppNode = NULL;
        }
        else
        {
            *ppNode = temp;

        }
    }
}

void List_isEmpty(const List_t *pl,bool_t *pstate)
{
    if(pl->pHead == NULL)
    {
        *pstate = TRUE;
    }
    else
    {
        *pstate = FALSE;
    }
}
