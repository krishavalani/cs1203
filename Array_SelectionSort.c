//Program in C to sort an array using selection sort

#include <stdio.h>
#include <stdlib.h>

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
    printf("These are the elements in the array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }

    //sorting the array
    for(int i = 0;  i<n; i++)
    {
        int temp = arr[i];
        int j = i -1;

        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    //printing the sorted array
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the sorted array: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }
}