#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int Monkey(int n, int x);

int main()
{
    int n,x;
    int result;
    printf("Input days n:");
    scanf("%d",&n);
    result=Monkey(n,x);
    printf("x=%d\n",result);
    return 0;
}

int Monkey(int n, int x)
{
    if (n==1) return 1;
    else return 2*(Monkey(n-1,x)+1);
}
