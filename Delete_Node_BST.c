//Program in C to delete node from a binarty search tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node *delete_node(node *root, int nod)
{   
    //if tree is empty return NULL
    if (root == NULL)
        return root;

    //if node to be deleted is smaller than root, then it lies in left subtree
    if (nod < root->data)
        root->left = delete_node(root->left, nod);

    //if node to be deleted is greater than root, then it lies in right subtree
    else if (nod > root->data)
        root->right = delete_node(root->right, nod);

    //if node to be deleted is same as root, then this is the node to be deleted
    else
    {   
        //node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        //node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void main()
{
    //user input to take size of array
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //defining an array of size n
    int arr[n];

    //user input for array elements
    for(int i = 0; i<n; i++)
    {
        printf("Enter element %d of the array: ", i+1);
        scanf("%d", &arr[i]);
    }

    //printing the array
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the array:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }

    //getting first element of the array
    int f1 = arr[0];
    //Creating a pointer by type-casting
    struct Node *A;
    A = (struct Node *) malloc(sizeof(struct Node));
    A->data = f1;
    A->left = NULL;
    A->right = NULL;

    //declaring head and pointers
    node *head, *p;
    head = A;
    p = head;

    //loop assign next nodes from array
    for(int i = 1; i<n; ++i)
    {
        f1 = arr[i];

        A = (struct Node *) malloc(sizeof(struct Node));
        A->data = f1;
        A->left = NULL;
        A->right = NULL;

        p = head;
        while (p != NULL)
        {
            if (f1 < p->data)
            {
                if (p->left == NULL)
                {
                    p->left = A;
                    break;
                }
                else
                    p = p->left;
            }
            else
            {
                if (p->right == NULL)
                {
                    p->right = A;
                    break;
                }
                else
                    p = p->right;
            }
        }
    }

    //printing the binary search tree
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the binary search tree:\n");
    p = head;
    while (p != NULL)
    {
        printf("%d \t", p->data);
        p = p->right;
    }

    //user input to take element to delete
    int nod;
    printf("\n-------------------------------------------\n");
    printf("Enter the element to deleted: ");
    scanf("%d", &nod);

    //checking if element to delete exists in the binary search tree
    p = head;
    int flag = 0;
    while (p != NULL)
    {
        if (nod == p->data)
        {
            flag = 1;
            break;
        }
        else if (nod < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if(flag != 1)
    {
        printf("-------------------------------------------\n");
        printf("Element to delete does not exist in the binary search tree.\n");
        exit(0);
    }

    //calling delete_node function
    head = delete_node(head, nod);

    //printing the updated binary search tree
    printf("-------------------------------------------\n");
    printf("These are the elements in the new binary search tree:\n");
    p = head;
    while (p != NULL)
    {
        printf("%d \t", p->data);
        p = p->right;
    }
}