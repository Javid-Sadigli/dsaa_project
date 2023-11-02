//including our header.
#include "dsaproject.h"

//freelist function frees the linked lists.
void freelist(T_Elector *head)
{
    T_Elector current = *head;
    while (current != NULL)
    {
        T_Elector temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("The memory is freed.\n");
}
//addelector function adds a newVoter to a linked list.
void addelector(T_Elector *ptr_to_head, char name[], long cin_num, int choice)
{
    T_Elector newVoter = (T_Elector) malloc(sizeof(elector));
    strcpy(newVoter->name, name);
    newVoter->choice = choice;
    newVoter->cin_num = cin_num;
    *ptr_to_head = insertSorted(*ptr_to_head, newVoter);
}
//displaylist function displays the linked list.
void displaylist(T_Elector head)
{
    T_Elector voter=head;
    printf("\nThe list of voters : ");
    int count = 1;
    while (voter != NULL)
    {
        printf("\n%d)Name : %s, ID number : %ld, Choice : %d ", count ,voter->name, voter->cin_num, voter->choice);
        voter = voter->next;
        count++;
    }
    printf("\n\n");
}
//creationelector function creates and returns a voter.
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
//creation_T_Elector_Linked_List function creates a linked list and returns its head.
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
//insertSorted function is defined by us. This function allows us to insert a new voter in sorted order and returns the head after sorting.
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
//alphaOrder is defined by us. This function checks the alphabetical order of 2 strings.
// If the return value is positive it means name1 and name 2 are not sorted.
int alphaOrder(const char *name1, const char *name2)
{
    return strcmp(name1, name2);
}
//countelector counts the number of voters in a list.
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
//findelector searches for a voter in the list by their ID number and returns 1 if found 0 if not found.
int findelector(T_Elector head, long cin_num)
{
    T_Elector voter = head;
    while (voter != NULL)
    {
        if (voter->cin_num == cin_num)
        {
            printf("Name : %s, ID number : %ld, Choice : %d\n", voter->name, voter->cin_num, voter->choice);
            return 1;
        }
        voter = voter->next;
    }
    printf("Voter does not exist in the list\n");
    return 0;
}
//decomposelist splits the k=original list into 3 lists while maintaining the original.
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
        T_Elector newNode = (T_Elector) malloc(sizeof(elector));

        strcpy(newNode->name, current->name);
        newNode->cin_num = current->cin_num;
        newNode->choice = current->choice;
        newNode->next = NULL;
        if (current->choice == 1 || current->choice == 3)
        {
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
        current = current->next;
    }
}
//deletelector deletes an elector in the list using their ID.
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

//sortlist sorts the list by ID numbers.
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

//mergelists merges the left and right lists and returns the head of the new list.
T_Elector mergelists(T_Elector headLeft, T_Elector headRight)
{
    T_Elector mergedList = NULL;
    T_Elector *current = &mergedList;

    T_Elector voterLeft = headLeft;
    T_Elector voterRight = headRight;
    if (headLeft == NULL || headRight == NULL)
    {
        printf("At least one of your lists doesn't exist\n");
        return headLeft;
    }
    else
    {
        while (voterLeft != NULL && voterRight != NULL)
        {
            T_Elector mergedElement;
            if (voterLeft->cin_num < voterRight->cin_num)
            {
                mergedElement = voterLeft;
                voterLeft = voterLeft->next;
            }
            else
            {
                mergedElement = voterRight;
                voterRight = voterRight->next;
            }
            *current = mergedElement;
            current = &(mergedElement->next);
        }
        if (voterLeft != NULL)
        {
            *current = voterLeft;
        }
        else if (voterRight != NULL)
        {
            *current = voterRight;
        }
    }
    return mergedList;
}

//countLR returns the number of left voters in the merged list.
int countLR(T_Elector mergedList)
{
    T_Elector voter = mergedList;
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