//preprocessor instructions.
#ifndef DSAPROJECT_H
#define DSAPROJECT_H
//macro constant definition.
#define MAX_NAME_SIZE 100
//library inclusions.
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct elector definition.
typedef struct elector
{
    char name[MAX_NAME_SIZE];
    long cin_num;
    int choice;
    struct elector *next;
} elector;
//renaming elector*.
typedef elector *T_Elector;

//function declarations.
T_Elector creationelector();

T_Elector creation_T_Elector_Linked_List();

T_Elector insertSorted(T_Elector head, T_Elector newVoter);

void displaylist(T_Elector head);

void addelector(T_Elector *ptr_to_head, char name[], long cin_num, int choice);

int alphaOrder(const char *name1, const char *name2);

void decomposelist(T_Elector head, T_Elector *headLeft, T_Elector *headRight, T_Elector *headWhite);

int countelector(T_Elector head);

int findelector(T_Elector head, long cin_num);

void deletelector(T_Elector *head, long cin_num);

void sortlist(T_Elector head);

void freelist(T_Elector *head);

T_Elector mergelists(T_Elector headLeft, T_Elector headRight);

int countLR(T_Elector mergedList);

#endif