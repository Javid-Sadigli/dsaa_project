#include <stdio.h>
#include <stdlib.h>
# define MAX_NAME_SIZE 100
typedef struct
{
    char name[MAX_NAME_SIZE];
    long cin_num;
    int choice;
    struct elector * next;
}elector;

typedef elector* T_Elector;

T_Elector creationelector();
T_Elector creation_T_Elector_Linked_List();

int main(int argc, char const *argv[])
{
    creation_T_Elector_Linked_List();
    return 0;
}

T_Elector creationelector()
{
    T_Elector voter = (T_Elector)malloc(sizeof(elector));
    printf("\nEnter the new voter's name : "); 
    scanf("%s", &(voter->name));
    printf("Enter the new voter's ID number : "); 
    scanf("%ld", &(voter->cin_num));
    printf("Enter the new voter's choice : "); 
    scanf("%d", &(voter->choice));
    voter->next = NULL;
    return voter; 
}

T_Elector creation_T_Elector_Linked_List()
{
    T_Elector head = NULL;
    
    int number_of_voters; 
    printf("\nEnter the number of voters : "); scanf("%d", &number_of_voters);
    T_Elector voter = creationelector();
    head = voter;
    for (int i = 1; i < number_of_voters; i++)
    {
        voter->next = creationelector();
        voter = voter->next;
    }
    return head;
}