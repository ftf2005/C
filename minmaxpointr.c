#include<stdio.h>
int main(){
     int a[10]={1,2,3,4,5};
    int *b;
    b=&a;
    int min=*b;
    int max=*b;
    for(int i=0;i<5;i++)
    {
       if(min>*b)
          min=*b;
       b++;
    }
    printf("%d\n",min);
    b=&a;
    for(int i=0;i<5;i++)
    {
       if(max<*b)
          max=*b;
       b++;
    }
    printf("%d\n",max);
}