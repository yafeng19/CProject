#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 100
void ZigzagMatrix(int a[][N], int n);
int main()
{
    int n;
    int a[N][N];
    printf("Input n:\n");
    scanf("%d",&n);
    if(n>0&&n<=100)
    {
        ZigzagMatrix(a,n);
    }
    else
        printf("Input error!\n");
    return 0;
}
void ZigzagMatrix(int a[][N], int n)
{
    int i,j,count=1;
    if(n%2!=0)
    {
        for(i=0;i<n;i++)
        {
            for (j=0;j<=i;j++)
            {
                if(i%2!=0)
                {
                    a[j][i-j]=count;
                    count++;
                }
                else
                {
                    a[i-j][j]=count;
                    count++;
                }
            }
        }
        for(i=1;i<=n-1;i++)
        {
            for (j=0;(j<=n-1)&&(i+j<n);j++)
            {
                if(i%2!=0)
                {
                    a[i+j][n-j-1]=count;
                    count++;
                }
                else
                {
                    a[n-j-1][j+i]=count;
                    count++;
                }
            }
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for (j=0;j<=i;j++)
            {
                if(i%2!=0)
                {
                    a[j][i-j]=count;
                    count++;
                }
                else
                {
                    a[i-j][j]=count;
                    count++;
                }
            }
        }
        for(i=1;i<=n-1;i++)
        {
            for (j=0;(j<=n-1)&&(i+j<n);j++)
            {
                if(i%2==0)
                {
                    a[i+j][n-j-1]=count;
                    count++;
                }
                else
                {
                    a[n-j-1][j+i]=count;
                    count++;
                }
            }
        }
    }



    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

}
