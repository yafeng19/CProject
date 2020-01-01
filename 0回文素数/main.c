#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, a, b;
    for (i = 2; i < 1000; i++)
    {
        if (prime(i))
        {
            if (i > 2 && i < 10)
                printf("%d\n", i);
            else
            {
                if (back(i))
                    printf("%d\n", i);
            }
        }
    }
}
int prime(int m)
{
    int i;
    for (i = 2; i < m; i++)
    {
        if (m % i == 0)
            return 0;
    }
    return 1;
}
int back(int m)
{
    int a, b;
    if (m >= 10 && m <= 99)
    {
        a = m / 10;
        b = m % 10;
        if (a == b)
            return 1;
    }
    else
    {
        a = m / 100;
        b = m % 10;
        if (a == b)
            return 1;
    }
    return 0;
}
