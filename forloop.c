#include<stdio.h>
int main()
{
    int n,i,x;
    printf("enter the szie of array:");
    scanf("%d",&x);
    int a[x];
    printf("enter the number of elements in array:");
    scanf("%d",&n);
    printf("enter the elements in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("the array elements are:");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
        
} 