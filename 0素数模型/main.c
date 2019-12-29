#include <stdio.h>
#include <stdlib.h>

int PrimeJudge(int n);
int main()
{
    int ret,n;
    scanf("%d",&n);
    ret=PrimeJudge(n);
    if(ret==0)
        printf("Non Prime\n");
    else
        printf("Prime\n");
    return 0;
}
int PrimeJudge(int n)
{
    int i;
    for (i=2;i<sqrt(n);i++)
    {
        if(n%i==0) return 0;
        else return 1;
    }
}
