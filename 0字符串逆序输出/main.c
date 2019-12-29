#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100],t;
    int i,n;
    scanf("%s",&str);
    n=strlen(str);
    for(i=0;i<n/2;i++)
    {
        t=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=t;
    }
    printf("%s\n",str);
    return 0;
}
