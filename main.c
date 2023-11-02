#include "dsaproject.h"
#include "project.c"

int main(int argc, char const *argv[])
{
    long idOfvoterSearched;
    long idOfvoterDeleted;
    T_Elector head = creation_T_Elector_Linked_List();
    T_Elector newVoter=creationelector();
    insertSorted(head,newVoter);
    printf("Enter the ID of the voter you want to delete: ");
    scanf("%ld",&idOfvoterDeleted);
    deletelector(&head,idOfvoterDeleted);
    printf("Enter the ID of the voter you want to search: ");
    scanf("%ld",&idOfvoterSearched);
    findelector(head,idOfvoterSearched);
    displaylist(head);

    return 0;
}