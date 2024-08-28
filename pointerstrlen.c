#include<stdio.h>
int main()
{
   char a[]="hello";
   char *b;
   b=&a;
   int len=0;
   while(*b!='\0')
   {
    len++;
    b++;
   }
   printf("Length of the string is %d\n", len);
}