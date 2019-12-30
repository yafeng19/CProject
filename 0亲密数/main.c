#include <stdio.h>
int getSum(int a);
int main()
{
    int a, b, n;
    scanf("%d", &n);
    for (a = 2; a <= n; a++)
    {
        b = getSum(a);  // 得到a的所有因子之和b
        if(a == getSum(b) && a<b)  // 检验b的因子之和是不是a，还要保证a<b
        printf("%d><%d\n", a, b);
    }
    return 0;
}
int getSum(int a)
{
    int i, s = 0;
    for (i = 1; i < a; i++)
    {
        if (a % i == 0)
            s += i;
    }
    return s;
}
