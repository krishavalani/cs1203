//Program in C to use pointers, malloc and realloc with 

#include <stdio.h>
#include <stdlib.h>
void main()
{   
    //Trying the malloc function in dynamic array in C
    printf("##TESTING MALLOC##\n");
    printf("-----------------------------\n");
    int n, i;
 
    // User input to get a fixed size of array
    printf("Enter number of elements in the array: ");
    scanf("%d",&n);
 
    // Dynamically allocate memory using malloc()
    int* ptr = (int*)malloc(n * sizeof(int));
    
    //storing values in the array, can be done by user, here:- we are storing i*2
    for (i = 0; i< n; i++)
    {
        ptr[i] = i*2;
    }
    
    //printing that address and array elements
    printf("Address: %p \n", ptr);
    for (i=0; i<n; i++)
    {
        printf("Value: %d \n", ptr[i]);
    }

    //Trying the calloc function in a dynamic array in C. This will assign zero to all spaces
    printf("-----------------------------\n");
    printf("##TESTING CALLOC##\n");
    printf("-----------------------------\n");
    int c;

    //User input for number of elements
    printf("Enter value of n: ");
    scanf("%d", &c);

    //Dynamically allocate memory using calloc()
    int* ctr = (int*)calloc(c,sizeof(int));

    //printing default values after calloc is carried out
    for(i =0; i<c; ++i)
    {
        printf("Value: %d \n", ctr[i]);
    }

    printf("-----------------------------\n");
    printf("##TESTING FREE##\n");
    printf("-----------------------------\n");
    //malloc and calloc functions have alredy been carried out we will be checking the results of the memory adress before and after using free

    if(ptr != NULL)
    {
        printf("Memory Present Post Malloc\n");
        printf("Address: %p \n", ptr);
        //using free
        free(ptr);
        printf("Memory has been freed\n");
    }
    else
    {
        printf("Memory is alredy empty\n");
    }

    if(ctr != NULL)
    {
        printf("Memory Present Post Calloc\n");
        printf("Address: %p \n", ctr);
        //using free
        free(ctr);
        printf("Memory has been freed\n");
        
    }
    else
    {
        printf("Memory is alredy empty\n");
    }
}
