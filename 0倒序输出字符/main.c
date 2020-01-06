#include <stdio.h>
#include <stdlib.h>
void fun(char *s)
{
    int i;
    int n=strlen(s);
    char temp;
    for(i=0;i<n/2;i++)
    {
        temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
    }
}
void main()
{
    char a[40]="abcdefg";
    fun(a);
    puts(a);
}
