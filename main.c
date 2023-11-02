//inclusion of headers.
#include "dsaproject.h"
#include<stdbool.h>
//main function.
int main(int argc, char const *argv[])
{
    //variable declarations.
    long id;
    int countmerged, countleft, countright, input;
    bool continues = true;
    T_Elector head = NULL;
    T_Elector headLeft = NULL;
    T_Elector headRight = NULL;
    T_Elector headWhite = NULL;
    T_Elector mergedHead = NULL;
    T_Elector newElector = NULL;
    while (continues)
    {
        //label
        input:
        printf("Press 1 to create the list of voters.\n");
        printf("Press 2 to add a new voter.\n");
        printf("Press 3 to delete a voter.\n");
        printf("Press 4 to search for a voter.\n");
        printf("Press 5 to display the list of voters.\n");
        printf("Press 6 to calculate the number of voters.\n");
        printf("Press 7 to split,sort and merge the main list of voters.\n");
        printf("Press 8 to calculate the percentages of the merged list.\n");
        printf("Press 9 to free the memory.\n");
        printf("Press 10 to quit.\n");
        scanf("%d", &input);
        printf("\n");
        //switch case for the input
        switch (input)
        {
            case 1:
                head = creation_T_Elector_Linked_List();
                printf("\nThe list of voters is ready.\n");
                printf("\n");
                break;
            case 2:
                printf("\nNow, please enter the new voter :");
                newElector = creationelector();
                addelector(&head, newElector->name, newElector->cin_num, newElector->choice);
                printf("\n");
                break;
            case 3:
                printf("\nNow, please enter the ID number to delete a voter : ");
                scanf("%ld", &id);
                deletelector(&head, id);
                printf("The voter with ID %ld has been deleted.\n", id);
                printf("\n");
                break;
            case 4:
                printf("\nNow, please enter the ID number to find a voter : ");
                scanf("%ld", &id);
                printf("The voter with ID %ld is : \n", id);
                findelector(head, id);
                printf("\n");
                break;
            case 5:
                displaylist(head);
                printf("\n");
                break;
            case 6:
                printf("For now, there are %d voters in your list.\n\n", countelector(head));
                break;
            case 7:
                decomposelist(head, &headLeft, &headRight, &headWhite);
                sortlist(headLeft);
                sortlist(headRight);
                sortlist(headWhite);
                printf("Left voters :");
                printf("\n");
                displaylist(headLeft);
                printf("Right voters :");
                printf("\n");
                displaylist(headRight);
                printf("White voters :");
                printf("\n");
                displaylist(headWhite);
                mergedHead = mergelists(headLeft, headRight);
                printf("\n");
                break;
            case 8:
                countmerged = countelector(mergedHead);
                countleft = countLR(mergedHead);
                countright = countmerged - countleft;
                printf("\nThe percentage of Left voters is approximately %.2lf %%\n",(((double) countleft) / ((double) countmerged)) * 100);
                printf("\nThe percentage of Right voters is approximately %.2lf %%\n",(((double) countright) / ((double) countmerged)) * 100);
                if (countleft > countright)
                {
                    printf("\nThe Left voters will probably win in the 2nd round. \n\n");
                }
                else if (countright > countleft)
                {
                    printf("\nThe Right voters will probably win in the 2nd round. \n\n");
                }
                else
                {
                    printf("\nBoth sides have equal chances for the 2nd round \n\n");
                }
                break;
            case 9:
                freelist(&head);
                freelist(&headLeft);
                freelist(&headRight);
                freelist(&headWhite);
                freelist(&mergedHead);
                break;
            case 10:
                printf("\nThank you!\n");
                continues = false;
                break;
            default:
                //if the user enters an invalid input they will be prompted again.
                printf("\nInvalid number input. Please enter again\n");
                goto input;
                break;
        }
    }
    return 0;
}