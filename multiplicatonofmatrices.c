//c program for multiplication of two matrices
#include<stdio.h>
void main()
{
    int a[10][10],b[10][10],c[10][10],i,j,k,n,m;
    printf("Enter the number of rows and columns of the first matrix:");
    scanf("%d%d",&n,&m);
    printf("Enter the elements of the first matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the number of rows and columns of the second matrix:");
    scanf("%d%d",&n,&m);
    printf("Enter the elements of the second matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("The multiplication of matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}


