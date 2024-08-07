//c program for addition of two matrices
#include<stdio.h>
void main()
{
    int a[100][100],b[100][100],c[100][100],i,j,row,col;   
    printf("Enter the number of rows and columns of the matrices:");
    scanf("%d%d",&row,&col);
    printf("Enter the elements of first matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("addition of  matrices:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
            printf("%d\t",c[i][j]);
        }
            printf("\n");
    }
}

