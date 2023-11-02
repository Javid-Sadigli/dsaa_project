#include "dsaproject.h"

int main(int argc, char const *argv[])
{
    T_Elector head = creation_T_Elector_Linked_List(); 
    printf("\nThe list of voters is ready.\n");


    printf("\nNow, please enter the new voter :");
    T_Elector newElector = creationelector();
    addelector(&head, newElector->name, newElector->cin_num, newElector->choice);

    long id; 
    printf("\nNow, please enter the ID number to delete a voter : ");
    scanf("%d", &id);
    deletelector(&head, id);
    printf("The voter with ID %d has been deleted.\n", id);

    printf("\nNow, please enter the ID number to find a voter : "); 
    scanf("%d", &id);
    printf("The voter with ID %d is : \n", id);
    findelector(head, id);

    displaylist(head);

    printf("For now, there are %d voters in your list.\n\n", countelector(head));
    
    T_Elector headLeft = NULL;
    T_Elector headRight = NULL;
    T_Elector headWhite = NULL;
    decomposelist(head, &headLeft, &headRight, &headWhite); 

    sortlist(headLeft);
    sortlist(headRight);
    sortlist(headWhite);

    printf("Left voters :");
    displaylist(headLeft);
    printf("Right voters :");
    displaylist(headRight);
    printf("White voters :");
    displaylist(headWhite);

    T_Elector mergedHead =  mergelists(headLeft, headRight);
    
    int countmerged = countelector(mergedHead);
    int countleft = countLR(mergedHead);
    int countright = countmerged - countleft;
    printf("\nThe percentage of Left voters is approximately %.2lf %%\n", (((double)countleft) / ((double)countmerged))*100);
    printf("\nThe percentage of Right voters is approximately %.2lf %%\n", (((double)countright) / ((double)countmerged))*100);
    if(countleft > countright)
    {
        printf("\nThe Left voters will probably win in the 2nd round. \n\n");
    }
    else if(countright > countleft)
    {
        printf("\nThe Right voters will probably win in the 2nd round. \n\n");
    }
    else
    {
        printf("\nBoth sides have equal chances for the 2nd round \n\n");
    }

    freelist(head);
    freelist(headLeft);
    freelist(headRight);
    freelist(headWhite);
    freelist(mergedHead);

    return 0;
}