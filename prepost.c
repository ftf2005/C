#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the values of a and b:");
    scanf("%d%d",&a,&b);
    //c=a-- + a++ - b++;
    c=++b - --a + ++b + a--;
    printf("%d\n",c);

}