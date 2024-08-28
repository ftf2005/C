#include<stdio.h>
int main()
{
    int a[10]={1,2,3,4,5};
    int *b;
    b=&a;
    for(int i=0;i<5;i++)
    {
        printf("%d\n",*b);
        printf("%p\n",b);
        b++;
    }
}