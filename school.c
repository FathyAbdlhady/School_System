
#include "school.h"

static void swap(student_t *a, student_t *b);



void main_Menu(void)
{
    u32 choice;
    List_t L1;
    List_init(&L1);
    printf("========================\n");
    printf("Welcome To Our School System\n");
    printf("========================\n");
    do{
        printf("========================\n");
        printf("1-Insert new student                2-Delete student\n3-Student list                      4-Edit student\n");
        printf("5-Update scores of students         6-Rank students\n7-Exit\n");
        printf("========================\n");


        printf("Please Enter choice: ");
        fflush(stdin);
        scanf("%ld",&choice);

        switch(choice)
        {
            case INSERT_NEW_STUDENT:
                new_Student(&L1);
                break;
            case DELETE_STUDENT:
                delete_Student(&L1);
                break;
            case STUDENT_LIST:
                student_List(&L1);
                break;
            case STUDENT_EDIT:
                student_Edit(&L1);
                break;
            case UPDATE_SCORE:
                student_Score(&L1);
                break;
            case RANK_STUDENT:
                student_Rank(&L1);
                break;
            case Exit:
                List_freeList(&L1);
                printf("\nThanks for using this program\n");
                break;
            default:
                printf("wrong choice\n");
                break;
        }
        printf("\n\n");

    }while(choice != 7);

}

void new_Student(List_t *pl)
{
    ListEntry e;
    printf("Please enter student information\n");
    printf("Student id: ");
    fflush(stdin);
    scanf("%hu",&(e.id));
    printf("Student Name: ");
    fflush(stdin);
    gets(e.name);
    printf("Student date of birth in format yyyy-mm-dd: ");
    fflush(stdin);
    gets(e.date_of_birth);
    printf("Student address: ");
    fflush(stdin);
    gets(e.address);
    printf("Student phone number: ");
    fflush(stdin);
    gets(e.phone_number);
    e.computer_science_grade = 0;

    List_insertNode(pl,&e);
}

void delete_Student(List_t *pl)
{
    ListEntry e;
    printf("Enter Student id: ");
    fflush(stdin);
    scanf("%hu",&(e.id));

    List_deleteNode(pl,&e);
}

void student_List(List_t *pl)
{
    List_print(pl);
}

void student_Edit(List_t *pl)
{
    u16 choice;
    ListNode_t *ppNode = NULL;
    ListEntry e;
    printf("Enter Student id: ");
    fflush(stdin);
    scanf("%hu",&(e.id));
    List_searchNode(pl, &e, &ppNode);

    if(ppNode != NULL)
    {
        printf("\n1-Change address\t2-Change date of birth\n3-Change phone number\n");

        printf("Please Enter choice: ");
        fflush(stdin);
        scanf("%hu",&choice);

        switch(choice)
        {
            case ADDRESS:
                printf("Student address: ");
                fflush(stdin);
                gets(ppNode->data.address);
                break;
            case DATE_OF_BIRTH:
                printf("Student date of birth in format yyyy-mm-dd: ");
                fflush(stdin);
                gets(ppNode->data.date_of_birth);
                break;
            case PHONE_NUMBER:
                printf("Student phone number: ");
                fflush(stdin);
                gets(e.phone_number);
                break;
            default:
                printf("wrong choice\n");
                break;
        }

    }
    else
    {
        printf("Edit can not be done because student is not in the list\n");
    }
}

void student_Rank(List_t *pl)
{

    bool_t state;
    List_isEmpty(pl,&state);

    if(state == TRUE)
    {
        printf("There are no students to rank\n");
    }
    else
    {
        u32 psize;
        List_listSize(pl,&psize);
        student_t *array = (student_t *)malloc( (psize) * (sizeof(student_t)) );
        if(array == NULL)
        {
            printf("There is a problem\n");
        }
        else
        {
            u16 i = 0,max,j;
            ListNode_t *temp;
            for(temp = pl->pHead; temp != NULL; temp = temp->pNext)
            {
                array[i] = temp->data;
                i++;
            }

            printf("Rank of Students\n");


            for (i = 0; i < (psize - 1); i++)
            {
                max = i;
                for (j = i + 1; j < psize; j++)
                {
                  if (array[j].computer_science_grade > array[max].computer_science_grade)
                  {
                      max = j;
                  }
                }
                swap(&array[max], &array[i]);

                printf("\nStudent %d\n",i+1);
                printf("Student Id = %d\n",array[i].id);
                printf("Student Name = %s\n",array[i].name);
                printf("Student score in computer science = %d\n",array[i].computer_science_grade);
           }
           printf("\nStudent %d\n",i+1);
           printf("Student Id = %d\n",array[i].id);
           printf("Student Name = %s\n",array[i].name);
           printf("Student score in computer science = %d\n",array[i].computer_science_grade);
           free(array);
        }
    }
}



void student_Score(List_t *pl)
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
        for(temp = pl->pHead; temp != NULL; temp = temp->pNext)
        {
            printf("\nId = %d\n",temp->data.id);
            printf("Name = %s\n",temp->data.name);
            printf("Please enter student score in computer science: ");
            scanf("%hu",&(temp->data.computer_science_grade));
        }
        printf("\nStudents scores have been set\n");
    }

}


static void swap(student_t *a, student_t *b)
{
  student_t temp = *a;
  *a = *b;
  *b = temp;
}

