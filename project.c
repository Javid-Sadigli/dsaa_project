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
void freelist(T_Elector head);
T_Elector mergelists(T_Elector headLeft, T_Elector headRight);
int countLR(T_Elector headLeft);
T_Elector allocate_for_elector();


int main(int argc, char const *argv[])
{
    T_Elector head = creation_T_Elector_Linked_List();
    displaylist(head);
    T_Elector headRight = NULL;
    T_Elector headLeft = NULL;
    T_Elector headWhite = NULL;
    decomposelist(head, &headLeft, &headRight, &headWhite);
    sortlist(head);
    sortlist(headWhite);
    //displaylist(headWhite);
    sortlist(headRight);
    //displaylist(headRight);
    sortlist(headLeft);
    //displaylist(headLeft);
    printf("\nHead :");
    displaylist(head);
    printf("\nLeft :");
    displaylist(headLeft);
    printf("\nRight : ");
    displaylist(headRight);
    printf("\nWhite :");
    displaylist(headWhite);
    freelist(head);
    printf("Freed list : \n");
    displaylist(head); 
    printf("\n");
    //printf("You have %d voters\n", countelector(head));
    //printf("%d", findelector(head, 1));
    return 0;
}

void freelist(T_Elector list)
{
    T_Elector temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
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

void decomposelist(T_Elector originalList, T_Elector *leftList, T_Elector *rightList, T_Elector *whiteList)
{
    // Initialize the sub-lists to NULL initially.
    *leftList = NULL;
    *rightList = NULL;
    *whiteList = NULL;

    T_Elector leftTail = NULL;
    T_Elector rightTail = NULL;
    T_Elector whiteTail = NULL;

    T_Elector current = originalList;

    while (current != NULL)
    {
        // Create a new node for the sub-list.
        T_Elector newNode = (T_Elector)malloc(sizeof(elector));
        if (newNode == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(1); // Handle memory allocation failure as needed.
        }

        // Copy the data from the original list node.
        strcpy(newNode->name, current->name);
        newNode->cin_num = current->cin_num;
        newNode->choice = current->choice;
        newNode->next = NULL;

        if (current->choice == 1 || current->choice == 3)
        {
            // Add to the left list.
            if (*leftList == NULL)
            {
                *leftList = newNode;
                leftTail = newNode;
            }
            else
            {
                leftTail->next = newNode;
                leftTail = newNode;
            }
        }
        else if (current->choice == 2 || current->choice == 4)
        {
            // Add to the right list.
            if (*rightList == NULL)
            {
                *rightList = newNode;
                rightTail = newNode;
            }
            else
            {
                rightTail->next = newNode;
                rightTail = newNode;
            }
        }
        else
        {
            // Add to the white list.
            if (*whiteList == NULL)
            {
                *whiteList = newNode;
                whiteTail = newNode;
            }
            else
            {
                whiteTail->next = newNode;
                whiteTail = newNode;
            }
        }

        // Move to the next node in the original list.
        current = current->next;
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


T_Elector mergelists(T_Elector headLeft, T_Elector headRight)
{
    T_Elector voterLeft = headLeft;
    if (headLeft == NULL || headRight == NULL)
    {
        printf("At least one of your lists doesn't exist\n");
        return headLeft;
    }
    else
    {
        while (voterLeft->next != NULL)
        {
            voterLeft = voterLeft->next;
        }
        voterLeft->next = headRight;
    }
    sortlist(headLeft);
    return headLeft;
}

int countLR(T_Elector headLeft)
{
    T_Elector voter = headLeft;
    int countLeftVoter = 0;
    while (voter != NULL)
    {
        if (voter->choice == 1 || voter->choice == 3)
        {
            countLeftVoter++;
        }
        voter = voter->next;
    }
    return countLeftVoter;
}

