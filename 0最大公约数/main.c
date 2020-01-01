#include <stdio.h>
#include <stdlib.h>
int Gcd(int a, int b);
int main()
{
    int m, n, result;
    printf("Input m,n:");
    scanf("%d,%d", &m, &n);
    result = Gcd(m, n);
    if (result == -1)
        printf("Input error!\n");
    return 0;
}
int Gcd(int a, int b)
{
    int i, max = 1;
    if (a >= 1 && a <= 10000 && b >= 1 && b <= 10000)
    {
        for (i = 1; i <= a || i <= b; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                max *= i;
                a /= i;
                b /= i;
            }
        }
        printf("%d/%d\n", a, b);
        printf("%d", max);
    }
    else
        return -1;
}
