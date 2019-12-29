#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,ret,f,l,i0;
    scanf("%d %d",&a,&b);
    for(i=a; i<=b; i++)
    {
        i0=i;
        l=i0%10;
        while(i0/10!=0)
        {
            i0=i0/10;
        }
        f=i0;
        if(f==l)
        {
            ret=prime(i);
            if(ret==1)
                printf("%d\n",i);
        }

    }
    return 0;
}
int prime(int n)
{
    int i;
    for(i=2; i<n; i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
