//write a c program for string arrays
#include<stdio.h>
#include<string.h>
int main(){
    char str[10][20];
    strcpy(str[0],"hello");
    strcpy(str[1],"world");
    for(int i=0;i<2;i++)
       printf("%s\n ",str[i]);
    return 0;
}

