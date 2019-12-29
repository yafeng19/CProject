#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    char a[20][200];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    for(i=0;i<n;i++)
    {
        if((a[strlen(a[i])-1]-'0')%2==0)
        {
            printf("even\n");
        }
        else
        {
            printf("odd\n");
        }
    }
    return 0;
}
