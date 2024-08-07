//write a c program for finding string length , copy other strings and concatenation
#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],str1[100],str2[100];
    int i;
    printf("Enter the string:");
    scanf("%s",str);
    printf("Length of string is:%d\n",strlen(str));
    printf("Enter the string to be copied:");
    scanf("%s",str1);
    strcpy(str2,str1);
    printf("Copied string is:%s\n",str2);
    printf("Enter the string to be concatenated:");
    scanf("%s",str1);
    strcat(str2,str1);
    printf("Concatenated string is:%s\n",str2);
}