//Programm in C to perform Qick Sort on Linked List

#include <stdio.h>
#include <stdlib.h>

//structure for a node
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

//function to create a node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to print the linked list
void printList(Node *head)
{
    Node *current = head;
    while(current != NULL)
    {
        printf("%d \t", current->data);
        current = current->next;
    }
}

//function to swap data of two nodes
void swap(Node *a, Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

//function to find the last node
Node *lastNode(Node *head)
{
    while(head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

//function to partition the linked list
Node *partition(Node *head, Node *end, Node **Head1, Node **End1)
{
    Node *pivot = end;
    Node *prev = NULL;
    Node *cur = head, *tail = pivot;

    while(cur != pivot)
    {
        if(cur->data < pivot->data)
        {
            if((*Head1) == NULL)
            {
                (*Head1) = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if(prev)
            {
                prev->next = cur->next;
            }
            Node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if((*Head1) == NULL)
    {
        (*Head1) = pivot;
    }

    //update End1 to the current last node
    (*End1) = tail;

    //return the pivot node
    return pivot;
}

Node *SortRecur(Node *head, Node *end)
{
    //base condition
    if(!head || head == end)
    {
        return head;
    }

    Node *Head1 = NULL, *End1 = NULL;

    //partition the list, Head1 and End1 will be updated by the partition function
    Node *pivot = partition(head, end, &Head1, &End1);

    if(Head1 != pivot)
    {
        Node *temp = Head1;
        while(temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;

        Head1 = SortRecur(Head1, temp);

        temp = lastNode(Head1);
        temp->next = pivot;
    }

    pivot->next = SortRecur(pivot->next, End1);

    return Head1;
}

//function to sort the linked list using quick sort
void quickSort(Node **headRef)
{
    (*headRef) = SortRecur(*headRef, lastNode(*headRef));
    return;
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
    Node *A;
    A = createNode(f1);

    //declaring head and pointers
    Node *head, *p;
    head = A;
    p = head;

    //loop to input next nodes from user
    for(int i = 1; i<n; ++i)
    {
        printf("Enter the next element in the linked list: ");
        scanf("%d", &f1);

        A = createNode(f1);

        //linking the notes
        p->next = A;

        //jumping to the current node
        p = p->next;
    }

    //displaying the linked list
    p = head;
    printf("-------------------------------------------\n");
    printf("These are the elements in the linked list: \n");
    printList(p);

    //sorting the given list using quick sort
    quickSort(&head);

    //displaying the sorted linked list
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the sorted linked list: \n");
    printList(head);
}