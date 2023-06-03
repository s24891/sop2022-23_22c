#include <stdio.h>
int main (void){
    int n = 0;
     int i;
    float sum;
    printf ("how many numbers to add up?  \n");
    scanf ("%d",&n);
    sum = 0;
   
    for (i = 0; i < n; i++) 
    {
        float numberToAdd = 0;
       printf("Enter %d the number to add:\n", i + 1);
        scanf ("%f",&numberToAdd);
        sum = sum + numberToAdd;
    }
       return sum;
}