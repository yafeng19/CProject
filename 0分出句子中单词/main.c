#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int Inverse(char str1[], char str2[][N]);
int main()
{
    char str1[N],str2[N][N],ch;
    int j,i;
    printf("Input a sentence:");
    gets(str1);
    ch=str1[strlen(str1)-1];
    str1[strlen(str1)-1]='\0';
    j=Inverse(str1,str2);
    for(i=j;i>0;i--)
    {
        printf("%s ",str2[i]);
    }
    printf("%s%c\n",str2[i],ch);
}
int Inverse(char str1[], char str2[][N])
{
    int i=0,j=0,k=0;
    while(str1[i]!=0)
    {
        k=0;
        while(str1[i]!=' '&&str1[i]!='\0')
        {
            str2[j][k]=str1[i];
            k++;
            i++;
        }
        str2[j][k]='\0';
        if(str1[i]=='\0')
            break;
        i++;
        j++;
    }
    return j;
}
