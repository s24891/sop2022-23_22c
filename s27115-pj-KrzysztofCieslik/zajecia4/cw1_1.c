#include <stdio.h>
int main (void){
    int n;
    float sum;
    int i; 
    n = 0;
    sum =0;
    i = 0;
    printf ("how many numbers to add up?  \n");
    scanf ("%d",&n);
   
    for (i=0;i < n; i++)
    {
        float numberToAdd = 0;
       printf("Enter %d the number to add:\n", i + 1);
        scanf ("%f",&numberToAdd);
        sum = sum + numberToAdd;
    }
       printf("Sum= %.2f\n",sum);
    return 0;
}