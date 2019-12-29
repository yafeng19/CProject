#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,j;
    char ch,temp='A';
    printf("Please input a capital:\n");
    scanf("%c",&ch);
    for (i=1;i<=ch-'A'+1;i++)
    {
        temp='A';
        for(j=1;j<2*(ch-'A'+1)+1;j++)
        {

            if(j>=(ch-'A'+2)-(i-1)&&j<=(ch-'A'+2))//中间列-（行-1）<=列<=中间列+（行-1）
            {
                printf("%c",temp);
                temp+=1;
            }
            else if(j<=(ch-'A'+2)+(i-1)&&j>(ch-'A'+2))
            {
                printf("%c",temp-2);
                temp-=1;
            }
            else if(j<(ch-'A'+2)-(i-1)) printf("%c",32);
        }
        printf("\n");
    }
    return 0;
}
