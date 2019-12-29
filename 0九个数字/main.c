#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,m;
    int a[10],sum=0;
    for(i=123;i<333;i++)
    {
        int a[10]={0};
        a[i/100]=1;
        a[i/10%10]=1;
        a[i%10]=1;
        j=2*i;
        a[j/100]=1;
        a[j/10%10]=1;
        a[j%10]=1;
        k=3*i;
        a[k/100]=1;
        a[k/10%10]=1;
        a[k%10]=1;
        sum=0;
        for(m=1;m<=9;m++)
        {
            sum+=a[m];
            if(sum==9)
                printf("%d %d %d\n",i,j,k);
        }
    }
    return 0;

}
