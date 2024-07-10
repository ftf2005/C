#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the value of a,b,c\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a>b || a>c)
    {
        if(a>c)
        {
            printf("a is greater");
        }
        else if(a<b) 
        {
            printf("a and b are same");
        }
        else
        {
            printf("a is smaller");
        }
    }
    else if(b==c)
    {
        printf("b and c are same");
    }
    else
    {
        printf("b is greater");
    }
}