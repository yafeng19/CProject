#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,a[5][5],sum1=0,sum2=0,sum3=0,s=0;
    int s1[5]={0},s2[5]={0},s3[5]={0};
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            s1[i]+=a[i][j];
        }
    }
    if(s1[1]==s1[2]&&s1[2]==s1[3]&&s1[3]==s1[4]&&s1[4]==s1[0])
    {
        for(j=0;j<5;j++)
        {
            for(i=0;i<5;i++)
            {
                s2[j]+=a[j][i];
            }
        }
        if(s2[1]==s2[2]&&s2[2]==s2[3]&&s2[3]==s2[4]&&s2[4]==s2[0])
        {
            for(i=0,j=0;i<5,j<5;i++,j++)
            {
                    s3[i]+=a[i][j];
            }
            if(s3[1]==s3[2]&&s3[2]==s3[3]&&s3[3]==s3[4]&&s3[4]==s3[0])
            {
                printf("It is a magic square!\n");
                for(i=0;i<5;i++)
                {
                    for(j=0;j<5;j++)
                    {
                        printf("%4d",a[i][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    else printf("It is not a magic square!\n");
    return 0;
}
