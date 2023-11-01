#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
typedef struct elector
{
    char name[MAX_NAME_SIZE];
    long cin_num;
    int choice;
    struct elector *next;
} elector;

typedef elector *T_Elector;

T_Elector creationelector();

T_Elector creation_T_Elector_Linked_List();

T_Elector insertSorted(T_Elector head, T_Elector newVoter);

void displaylist(T_Elector head);

void addelector(T_Elector *ptr_to_head, char name[], long cin_num, int choice);

int alphaOrder(const char *name1, const char *name2);

void decomposelist(T_Elector head, T_Elector *headLeft, T_Elector *headRight, T_Elector *headWhite);

int countelector(T_Elector head);

int findelector(T_Elector head, long cin_num);

int main(int argc, char const *argv[])
{
    T_Elector head = creation_T_Elector_Linked_List();
    displaylist(head);
    displaylist(head);
    printf("\n");
    printf("You have %d voters\n", countelector(head));
    printf("%d", findelector(head, 1));
    return 0;
}

void addelector(T_Elector *ptr_to_head, char name[], long cin_num, int choice)
{
    T_Elector newVoter = (T_Elector) malloc(sizeof(elector));
    strcpy(newVoter->name, name);
    newVoter->choice = choice;
    newVoter->cin_num = cin_num;
    *ptr_to_head = insertSorted(*ptr_to_head, newVoter);
}

void displaylist(T_Elector head)
{
    printf("\nHead -> ");
    while (head != NULL)
    {
        printf("{Name : %s, ID number : %ld, Choice : %d} -> ", head->name, head->cin_num, head->choice);
        head = head->next;
    }
    printf("NULL\n");
}

T_Elector creationelector()
{
    T_Elector voter = (T_Elector) malloc(sizeof(elector));
    printf("\nEnter the new voter's name: ");
    scanf("%s", voter->name);
    printf("Enter the new voter's ID number: ");
    scanf("%ld", &(voter->cin_num));
    printf("Enter the new voter's choice: ");
    scanf("%d", &(voter->choice));
    voter->next = NULL;
    return voter;
}

T_Elector creation_T_Elector_Linked_List()
{
    T_Elector head = NULL;
    T_Elector newVoter;
    int number_of_voters;
    printf("\nEnter the number of voters: ");
    scanf("%d", &number_of_voters);
    for (int i = 0; i < number_of_voters; i++)
    {
        newVoter = creationelector();
        head = insertSorted(head, newVoter);
    }
    return head;
}

T_Elector insertSorted(T_Elector head, T_Elector newVoter)
{
    if (head == NULL || alphaOrder(newVoter->name, head->name) < 0)
    {
        newVoter->next = head;
        return newVoter;
    }
    T_Elector current = head;
    while (current->next != NULL && alphaOrder(newVoter->name, current->next->name) >= 0)
    {
        current = current->next;
    }
    newVoter->next = current->next;
    current->next = newVoter;
    return head;
}

int alphaOrder(const char *name1, const char *name2)
{
    return strcmp(name1, name2);
}

int countelector(T_Elector head)
{
    T_Elector voter = head;
    int count = 0;
    while (voter != NULL)
    {
        count++;
        voter = voter->next;
    }
    return count;
}

int findelector(T_Elector head, long cin_num)
{
    T_Elector voter = head;
    while (voter != NULL)
    {
        if (voter->cin_num == cin_num)
        {
            printf("{Name : %s, ID number : %ld, Choice : %d} -> ", voter->name, voter->cin_num, voter->choice);
            return 1;
        }
        voter = voter->next;
    }
    printf("Voter does not exist in the list\n");
    return 0;
}


void decomposelist(T_Elector head, T_Elector *headLeft, T_Elector *headRight, T_Elector *headWhite)
{
    T_Elector voter = head;
    T_Elector left = NULL;
    T_Elector right = NULL;
    T_Elector white = NULL;
    while (voter != NULL)
    {
        if (voter->choice == 1 || voter->choice == 3)
        {
            // Add the voter to the left list
            if (*headLeft == NULL)
            {
                *headLeft = voter;
                left = voter;
            }
            else
            {
                left->next = voter;
                left = voter;
            }
        }
        else if (voter->choice == 2 || voter->choice == 4)
        {
            // Add the voter to the right list
            if (*headRight == NULL)
            {
                *headRight = voter;
                right = voter;
            }
            else
            {
                right->next = voter;
                right = voter;
            }
        }
        else
        {
            // Add the voter to the white list
            if (*headWhite == NULL)
            {
                *headWhite = voter;
                white = voter;
            }
            else
            {
                white->next = voter;
                white = voter;
            }
        }
        voter = voter->next;
    }

    // Make sure to terminate the lists
    if (left != NULL)
    {
        left->next = NULL;
    }
    if (right != NULL)
    {
        right->next = NULL;
    }
    if (white != NULL)
    {
        white->next = NULL;
    }
}