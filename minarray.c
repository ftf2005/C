#include<stdio.h>
int main()
{
    int a[100],n,i,min,max;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    while(i<n)
    {
        scanf("%d",&a[i]);
        i++;
    }
    min=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    printf("The minimum element in the array is %d\n",min);
}