#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int SearchString(char s[], char d[]);
int main()
{
    char s[N],d[N];
    int ret;
    printf("Input a string:");
    gets(s);
    printf("Input another string:");
    gets(d);
    ret=SearchString(s,d);
    if(ret!=-1)
        printf("Searching results:%d\n",ret);
    else
        printf("Not found!\n");
    return 0;
}
int SearchString(char s[], char d[])
{
    int i,j,a,len=0;
    for(i=0;i<strlen(s);i++)
    {
        if(d[0]==s[i])
        {
            for(j=0,a=i;j<strlen(d);j++,a++)
            {
                if(d[j]==s[a])
                len++;
            }
            if (len==strlen(d))
                return i+1;
            else
                len=0;
        }
    }
    return -1;
}
