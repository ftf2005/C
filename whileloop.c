#include<stdio.h>
int main()
{
    int n,i,a[100];
    printf("size");
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%d",&a[i]);
        i++;
    }
    i=0;
    printf("elements are:");
    while(i<n)
    {
        printf("%d\n",a[i]);
        i++;
    }
    
}