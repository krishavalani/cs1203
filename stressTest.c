//Program to stress Testing Loops in C, checking when computer makes an error on increasing floating point numbers

#include <stdio.h>
#include <stdlib.h>

//alter value of m in order to find the number of time you can run befire the computer makes an errot

void main()
{
    //these are the first m and n values where the stress test fails
    float m = 0.00000000000000001; // this value, 'm' can be tampered
    float n = 0.0000000000000001; // this value, 'n' can be tampered
    int c = 1;
    
    //addidng one at every interation
    for (float i=0.0; i<n; i+=m) 
    {
        printf("%d\n", c);
        c+=1;
    }
    // printing m+n valus as a floating point
    //for (float i=0.0; i<n; i+=m) 
   // {
    //    printf("%f\n", m+n);
    //}
}