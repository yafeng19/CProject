#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
int Prime(int n);
int main()
{
    int n,a[N],sum=0,i,j=0,ret,count=0,j0;
    printf("Input n(n<=500):");
    scanf("%d",&n);
        for(i=2;i<n;i++)
        {
            ret=Prime(i);
                if(ret!=0)
                {
                    a[j]=ret;
                    j++;
                }
        }
    if(n>29)
    {
        for(j--;count<10;j--)
        {
            printf("%6d",a[j]);
            sum+=a[j];
            count++;
        }
        printf("\nsum=%d\n",sum);
    }
    else
    {
        j0=j;
        for(j--;count<j0;j--)
        {
            printf("%6d",a[j]);
            sum+=a[j];
            count++;
        }
        printf("\nsum=%d\n",sum);
    }
    return 0;
}
int Prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return n;
}
