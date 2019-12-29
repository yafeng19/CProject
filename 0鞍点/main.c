#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 10
void FindSaddlePoint(int a[][N], int m, int n);
int main()
{
    int a[M][N];
    int i,j,m,n;
    printf("Input m,n:\n");
    scanf("%d,%d",&m,&n);
    printf("Input matrix:\n" );
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    FindSaddlePoint(a,m,n);
    return 0;
}

void FindSaddlePoint(int a[][N], int m, int n)
{
    int minnumber,maxnumber;
    int i,j,k=0,l=0;
    for(i=0;i<m;i++)
    {
        maxnumber=a[i][0];
        for(j=0;j<n;j++)
        {
            if(a[i][j]>maxnumber)
            {
                maxnumber=a[i][j];
                k=j;
            }
        }
        maxnumber=a[i][k];
        minnumber=maxnumber;
        for(i=0;i<m;i++)
        {
            if(a[i][k]<minnumber)
            {
                minnumber=a[i][k];
                l=i;
            }
        }
        if(l==0&&k==0)
        {
            printf("No saddle point!\n");
            return 0;
        }
        if(maxnumber==minnumber)
        {
            printf("a[%d][%d] is %d\n",l,k,maxnumber);
            return 0;
        }
    }
    printf("No saddle point!\n");

}
