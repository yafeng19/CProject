#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand((unsigned)time(NULL));
    int a=rand()%10,b=rand()%10,c,k=rand()%2;
    if(a>=b)
    {
        c=a-b;
        a=b+c;
        if(k==0)
        {
            printf("%d-%d=",a,b);
        }
        else
        {
            printf("%d+%d=",b,c);
        }
    }
    else
    {
        c=b-a;
        b=a+c;
        if(k==0)
        {
            printf("%d-%d=",b,a);
        }
        else
        {
            printf("%d+%d=",a,c);
        }
    }
    return 0;
}
