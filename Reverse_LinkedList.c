//Program in C to reverse a linked list of size n

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

    //displaying to the linked list
    p = head;
    printf("-------------------------------------------\n");
    printf("These are the elements in the linked list:\n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }    
    
    //reversing the list
    struct Node *p_node, *c_node, *n_node;
    p_node = NULL;
    c_node = head;
    n_node = NULL;


 while(c_node != NULL)
    {
        n_node = c_node->link;
        c_node->link = p_node;
        p_node = c_node;
        c_node = n_node;
    }
    head = p_node;

    //displaying the reversed linked list
    p = head;
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the reversed linked list:\n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }

}