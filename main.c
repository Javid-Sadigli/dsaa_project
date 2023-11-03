//inclusion of headers.
#include "dsaproject.h"
//main function.
int main(int argc, char const *argv[])
{
    //variable declarations.
    long id;
    int countmerged, countleft, countright, input;
    bool continues = true;
    bool continues2 = true;
    char c;
    T_Elector head = NULL;
    T_Elector headLeft = NULL;
    T_Elector headRight = NULL;
    T_Elector headWhite = NULL;
    T_Elector mergedHead = NULL;
    T_Elector newElector = NULL;

    printf("\n");
    while (continues)
    {
        //label
        input:
        printf("\nChoose 1 to create the list of voters.\n");
        printf("Choose 2 to add a new voter.\n");
        printf("Choose 3 to delete a voter.\n");
        printf("Choose 4 to search for a voter.\n");
        printf("Choose 5 to display the list of voters.\n");
        printf("Choose 6 to calculate the number of voters.\n");
        printf("Choose 7 to split,sort and merge the main list of voters.\n");
        printf("Choose 8 to calculate the percentages of the merged list.\n");
        printf("Choose 9 to free the memory.\n");
        printf("Choose 10 to quit.\n");
        printf("Enter your choice : ");
        scanf("%d", &input);
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
                newElector = creationelector(head);
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
                if(!findelector(head, id))
                {
                    printf("Voter does not exist in the list");
                };
                printf("\n\n");
                break;
            case 5:
                displaylist(head);
                printf("\n");
                break;
            case 6:
                printf("For now, there are %d voters in your list.\n\n", countelector(head));
                break;
            case 7:
                continues2 = true;
                while (continues2)
                {
                    printf("\nChoose 'a' to split and sort the list into 3 sublists\n");
                    printf("Choose 'b' to display the sublists\n");
                    printf("Choose 'c' to merge two sublists\n");
                    printf("Choose 'q' to quit\n");
                    printf("Enter your choice : ");
                    scanf(" %c", &c);
                    switch (c)
                    {
                        case 'a':
                            decomposelist(head, &headLeft, &headRight, &headWhite);
                            sortlist(headLeft);
                            sortlist(headRight);
                            sortlist(headWhite);
                            printf("Lists split and sorted.\n");
                            break;
                        case 'b':
                            printf("Left voters:\n");
                            displaylist(headLeft);
                            printf("Right voters:\n");
                            displaylist(headRight);
                            printf("White voters:\n");
                            displaylist(headWhite);
                            break;
                        case 'c':
                            if (headLeft == NULL || headRight == NULL)
                            {
                                printf("Atleast one of the lists is emptyq"
                                       ".\n");
                            }
                            else
                            {
                                mergedHead = mergelists(headLeft, headRight);
                                printf("Lists merged.\n");
                            }
                            break;
                        case 'q':
                            continues2 = false;
                            break;
                        default:
                            printf("Invalid character. Please enter a valid input.\n");
                            break;
                    }
                }
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
                printf("\n");
                freelist(&head);
                freelist(&headLeft);
                freelist(&headRight);
                freelist(&headWhite);
                freelist(&mergedHead);
                printf("\n");
                break;
            case 10:
                printf("\nThank you!\n\n");
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