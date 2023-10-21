#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED

#include "list.h"

#define INSERT_NEW_STUDENT      1
#define DELETE_STUDENT          2
#define STUDENT_LIST            3
#define STUDENT_EDIT            4
#define UPDATE_SCORE            5
#define RANK_STUDENT            6
#define Exit                    7

#define ADDRESS             1
#define DATE_OF_BIRTH       2
#define PHONE_NUMBER        3


void main_Menu(void);

void new_Student(List_t *pl);

void delete_Student(List_t *pl);

void student_List(List_t *pl);

void student_Edit(List_t *pl);

void student_Rank(List_t *pl);

void student_Score(List_t *pl);

#endif // SCHOOL_H_INCLUDED
