#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int main()
{
    char s1[N], s2[N];
    int i;
    gets(s1);
    gets(s2);
    for (i = 0; i < strlen(s1) && i < strlen(s2); i++)
    {
        if (s1[i] == s2[i])
        {
            printf("%c", s1[i]);
        }
        else
        {
            printf(" ");
        }
    }
}
