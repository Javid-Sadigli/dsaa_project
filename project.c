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

// Function prototypes
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

int main(int argc, char const *argv[])
{
    T_Elector head = creation_T_Elector_Linked_List();

    T_Elector headRight = NULL;
    T_Elector headLeft = NULL;
    T_Elector headWhite = NULL;
    decomposelist(head, &headLeft, &headRight, &headWhite);
    sortlist(head);
    sortlist(headWhite);
    sortlist(headRight);
    sortlist(headLeft);
    displaylist(head);
    displaylist(headLeft);
    displaylist(headRight);
    displaylist(headWhite);
    printf("\n");
    //printf("You have %d voters\n", countelector(head));
    //printf("%d", findelector(head, 1));
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
    printf("The options for new voter's choice are as below: \n");
    printf("NAME1: 1\n");
    printf("NAME2: 2\n");
    printf("NAME3: 3\n");
    printf("NAME4: 4\n");
    printf("NAME5: 5\n");
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

void deletelector(T_Elector *head, long cin_num)
{
    T_Elector ptr_to_deleting_voter = *head;
    if (ptr_to_deleting_voter->cin_num == cin_num)
    {
        (*head) = ptr_to_deleting_voter->next;
        free(ptr_to_deleting_voter);
        return;
    }
    T_Elector deleting_voter = ptr_to_deleting_voter->next;
    while (deleting_voter->cin_num != cin_num && deleting_voter != NULL)
    {
        ptr_to_deleting_voter = ptr_to_deleting_voter->next;
        deleting_voter = ptr_to_deleting_voter->next;
    }
    if (deleting_voter == NULL)
    {
        return;
    }
    ptr_to_deleting_voter->next = deleting_voter->next;
    free(deleting_voter);
}


void sortlist(T_Elector head)
{
    T_Elector voter = head;
    long tempVal;
    int swapped = 1;
    if (voter == NULL)
    {
        printf("Your list doesn't exist\n");
    }
    else
    {
        while (swapped)
        {
            swapped = 0;
            voter = head;
            while (voter->next != NULL)
            {
                if (voter->cin_num > voter->next->cin_num)
                {
                    tempVal = voter->cin_num;
                    voter->cin_num = voter->next->cin_num;
                    voter->next->cin_num = tempVal;
                    swapped = 1;
                }
                voter = voter->next;
            }
        }
    }
}