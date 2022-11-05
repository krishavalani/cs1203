//Program in C to perform Quick Sort on an array

#include <stdio.h>
#include <stdlib.h>
//fucntion to swap two elements in the array
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

//function to divide the array
int divide(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i+1, high);
    return i+1;
}

//function to perform quick sort
void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = divide(a, low, high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
}
void main()
{
    //user input to take size of the array
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
    printf("These are the elements in the array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }

    //calling functions
    quickSort(arr, 0, n-1);

    //printing the sorted array
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the sorted array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }
    
}