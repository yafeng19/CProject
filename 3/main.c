#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,sum=1,sum0,sum2=1;
    scanf("%d",&n);
    for(i=1; i<n; i++)
    {
        for(j=2; j<n; j++)
        {
            if(i%j==0)
            {
                sum+=j;
                i/=j;
                j--;
            }
        }
        for(j=2; j<n; j++)
        {
            if(sum%j==0)
            {
                sum2+=j;
                sum/=j;
                j--;
            }
        }
        if(sum0==sum2)
        {
            printf("%d %d",sum0,sum2);
        }
    }
    return 0;
}
