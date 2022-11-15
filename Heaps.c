//Program in C to build an heap using an array and the sorting it using selection sort

#include <stdio.h>
#include <stdlib.h>

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

    //heapyfying the array
    for(int i = n/2 - 1; i >= 0; i--)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n && arr[left] > arr[largest])
        {
            largest = left;
        }
        if(right < n && arr[right] > arr[largest])
        {
            largest = right;
        }
        if(largest != i)
        {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
        }
    }

    //printing the heap
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the heap: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }

    //sorting the heap
    for(int i = n-1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int largest = 0;
        int left = 2*largest + 1;
        int right = 2*largest + 2;

        if(left < i && arr[left] > arr[largest])
        {
            largest = left;
        }
        if(right < i && arr[right] > arr[largest])
        {
            largest = right;
        }
        if(largest != 0)
        {
            int temp = arr[0];
            arr[0] = arr[largest];
            arr[largest] = temp;
        }
    }

    //printing the sorted heap
    printf("\n-------------------------------------------\n");
    printf("These are the elements in the sorted heap: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d \t", arr[i]);
    }
}

