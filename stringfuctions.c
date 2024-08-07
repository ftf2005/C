//write a c program for finding string length , copy other strings and concatenation
#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],str1[100];
    printf("Enter the string:");
    scanf("%s",str);
    printf("Length of string is:%d \n",strlen(str));
    printf("Enter the string to be copied:");
    scanf("%s",str1);
    strcpy(str1,str);
    printf("Copied string is:%s\n",str1);
    printf("Concatenated string is:%s\n",  strcat(str1,str));
    // printf("reverse:%d\n",strrev(str));

}