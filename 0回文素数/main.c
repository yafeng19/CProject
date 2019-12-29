#include <stdio.h>
#include <stdlib.h>
int Prime (int n);
int main()
{
    int i,ret;
    int a,b;
    for (i=2;i<1000;i++)
    {
        ret=Prime(i);
        if (ret>=100)
        {
            a=i/100;
            b=i%10;
            if(a==b)
                printf("%d\n",ret);
        }
        else if(ret>=10&&ret<=99)
        {
            a=i/10;
            b=i%10;
            if(a==b)
                printf("%d\n",ret);
        }
        else if(ret>=2&&ret<=9)
            printf("%d\n",ret);
        else continue;
    }
}
int Prime (int n)
{
    int j;
    for(j=2;j<=sqrt(n);j++)
    {
        if(n%j==0)
            return 0;
    }
    return n;
}
