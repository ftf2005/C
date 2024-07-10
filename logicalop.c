#include<stdio.h>
int main()
{
    int a , b,c=10;
    printf("enter the values of a and b:");
    scanf("%d%d",&a,&b);
    if(a+b<c)
    {
        printf("hello\n");
    }
    else if(a+b != c)
    {
        printf("hi");
    }
    if(a<c && a>b)
    {
        printf("hola\n");
    }
    if(a<b || b<c)
    {
        printf("hello world\n");
    }
}