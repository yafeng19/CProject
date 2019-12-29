#include <stdio.h>
int CountWords(char str[]);
int main()
{
    char  str[81];
    int num;
    printf("Input a string:\n");
    gets(str);
    num=CountWords(str);
    printf("Number of words=%d\n", num);
    return 0;
}

int CountWords(char str[])
{
    int  i, num;
    num = ( str[0] != ' ') ? 1 : 0;
    i=1;
    while (str[i]!='\0')
    {
        if ( str[i]!=' ' && str[i-1] == ' ')
        {
            num++;
        }
        i++;
    }
    return num;
}
