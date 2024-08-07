#include<stdio.h>
int main()
{
    int a[100],n,i,max,min;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    while(i<n)
    {
        scanf("%d",&a[i]);
        i++;
    }
    max=a[0];
    i=0;
    while(i<n)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
        i++;
    }
    min=a[0];
    i=0;
    while(i<n)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        i++;
    }
    printf("The minimum element in the array is %d\n",min);
    printf("The maximum element in the array is %d\n",max);
}