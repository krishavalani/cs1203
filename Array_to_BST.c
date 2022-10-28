//Program in C to convert an array of size n to a binary search tree

#include <stdio.h>
#include <stdlib.h>

//defiing a tree node
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
}Node;


//creating a tree node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data; 
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

//converting the array to a binary search tree
Node *arrayToBST(int *a, int n)
{
    Node *root = createNode(a[0]);
    Node *current = root;
    for(int i = 0; i<n; i++)
    {
        current = root;
        while (current != NULL)
        {
            if (a[i] > current->data)
            {
                if(current->right == NULL)
                {
                    //assining the right child the larger dataue
                    current->right = createNode(a[i]);
                    current->right->parent = current;
                    break;

                }
                else
                {
                    current = current->right;
                }
            }
            else
            {
                //assining the left child the smaller dataue
                if(current->left == NULL)
                {
                    current->left = createNode(a[i]);
                    current->left->parent = current;
                    break;
                }
                else
                {
                    current = current->left;
                }
                
            }
        }
    }
    return root;
}
void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->right);
    printf("%d ", root->data);
    printTree(root->left);
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
    printf("-------------------------------------------\n");
    printf("These are the elements in the array:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }

    Node *root = arrayToBST(arr, n);
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the BST:\n");
    printTree(root);
}