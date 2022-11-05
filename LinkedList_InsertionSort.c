//Progran in C to perform insertion sort in linked lists

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void main()
{
    //user input to take size of linked list
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //user input to take first element of the liked list
    int f1;
    printf("Enter the first element in the linked list: ");
    scanf("%d", &f1);

    //Creating a pointer by type-casting
    struct Node *A;
    A = (struct Node *) malloc(sizeof(struct Node));
    A->data = f1;
    A->link = NULL;

    //declaring head and pointers
    struct Node *head, *p;
    head = A;
    p = head;

    //loop to input next nodes from user
    for(int i = 1; i<n; ++i)
    {
        printf("Enter the next element in the linked list: ");
        scanf("%d", &f1);

        A = (struct Node *) malloc(sizeof(struct Node));
        A->data = f1;
        A->link = NULL;

        //linking the notes
        p->link = A;

        //jumping to the current node
        p = p->link;
    }

    //displaying the linked list
    p = head;
    printf("-------------------------------------------\n");
    printf("These are the elements in the linked list: \n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }

    //sorting the given list using insertion sort
    struct Node *i, *j, *k;
    i = head;
    
    j = i->link;
    k = j->link;

    for(i = head; i->link != NULL; i = i->link)
    {
        for(j = i->link; j != NULL; j = j->link)
        {
            if(i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    //displaying the sorted linked list
    p = head;
    printf("-------------------------------------------\n");
    printf("These are the elements in the sorted linked list: \n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }
}