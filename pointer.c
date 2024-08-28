#include<stdio.h>
int main()
{
    int a =5 ;
    int *b;
    b=&a;
    printf("%d value of a\n",a);
    printf("%p value of b\n",b);
    printf("%d value of b\n",*b);


}