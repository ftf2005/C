#include<stdio.h>
int main(){
     int a[10]={1,2,3,4,5};
    int *b;
    b=&a;
    int sum=0;
    for(int i=0;i<5;i++)
    {
       sum+=*b;
       b++;
    }
    printf("%d",sum);
}