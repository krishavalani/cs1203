//Program in C to chunk reverse a linked list. Given head pointer of a linked list, and an integer k (1<=k<=n), reverse every k elements of the list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node node;

node *creverse(node *head, int k)
{
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;

    //reverse first k nodes of the linked list
    while (current != NULL && count < k)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
        count++;
    }

    //next is now a pointer to (k+1)th node
    if (next != NULL)
        head->link = creverse(next, k);

    //prev is now a pointer to the kth node
    return prev;
}

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

    //user input to take k
    int k;
    printf("\n-------------------------------------------\n");
    printf("Enter the value of k: ");
    scanf("%d", &k);

    //checking if k is valid
    if(k<1 || k>n)
    {
        printf("Invalid value of k. Please enter a value between 1 and %d", n);
        exit(0);
    }

    //calling the reverse function
    head = creverse(head, k);

    //displaying reversed linked list
    p = head;
    printf("-------------------------------------------\n");
    printf("These are the elements in the reversed linked list:\n");
    while(p != NULL)
    {
        printf("%d \t", p->data);
        p = p->link;
    }
}