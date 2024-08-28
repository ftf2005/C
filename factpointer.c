#include<stdio.h>
int main(){
    int a=5;
    int *b;
    b=&a;
    for(int i=*b-1;i>0;i--)
    {
        *b=i*(*b);
    }
    printf("%d\n",*b);
}