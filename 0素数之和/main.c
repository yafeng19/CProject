#include <stdio.h>
#include <stdlib.h>
int IsPrime(int x);
int main()
{
    int n,sum=0;
    printf("Input n:");
    scanf("%d",&n);
    sum=IsPrime(n);
    printf("sum=%d\n",sum);

}
int IsPrime(int x)
{
    int i,j,sum0=0;
    if(x<=0) return 0;
    else
    {
        for(i=2;i<=x;i++)
        {
            for(j=2;j<i;j++)
            {
                if(i%j==0) break;
            }
            if (i==j) sum0+=i;
        }
        return sum0;
    }
}
