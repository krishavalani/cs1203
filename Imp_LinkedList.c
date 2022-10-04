//Program in C to implement a linked list of size n

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
    int head;
    printf("Enter the first element in the linked list: ");
    scanf("%d", &head);

    //Creating a pointer by type-casting
    struct Node *A;
    A = (struct Node *) malloc(sizeof(struct Node));
    A->data = head;
    A->link = NULL;

    //declaring head and pointers
    struct Node *h1, *p;
    h1 = A;
    p = h1;

    //loop to input next nodes from user
    for(int i = 1; i<n; ++i)
    {
        printf("Enter the next element in the linked list: ");
        scanf("%d", &head);

        A = (struct Node *) malloc(sizeof(struct Node));
        A->data = head;
        A->link = NULL;

        //linking the notes
        p->link = A;

        //jumping to the current node
        p = p->link;
    }

    //displaying to the linked list
    p = h1;
    printf("-------------------------------------------\n");
    printf("These are the elements in the linked list:\n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }
}