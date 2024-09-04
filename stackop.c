//write a c program for stack operation push, pop
#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int x){
    if(top==MAX-1)
    {
        printf("Stack is full. Overflow condition!\n");
    }
    else
    {
        stack[++top]=x;
        printf("Element pushed to the stack: %d\n",x);
    }
}
void pop(){
    if(top==-1)
    {
        printf("Stack is empty. Underflow condition!\n");
    }
    else
    {
        printf("Element popped from the stack: %d\n",stack[top--]);
    }
}
void display(){
    if(top==-1)
    {
        printf("Stack is empty. Nothing to display!\n");
    }
    else
    {
        int i;
        for(i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
            printf("\n");
        }
    }
}
int main(){
    int choice,x;
    printf("1: Push\n2: Pop\n3: Display\n4: Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
}


    




