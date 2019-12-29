#include <stdio.h>
#include <stdlib.h>
typedef struct score
{
    int num;
    int Math;
    int Chinese;
    int English;
}SCORE;
int main()
{
    SCORE stu[3];
    int i,j,temp,sum[3];
    float aver[3];
    for(i=0;i<3;i++)
    {
        scanf("%d%d%d%d",&stu[i].num,&stu[i].Math,&stu[i].Chinese,&stu[i].English);
        sum[i]=(stu[i].Math+stu[i].Chinese+stu[i].English);
        aver[i]=(float)(sum[i])/3;
    }
    for(i=0;i<2;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(sum[j]>sum[i])
            {
                temp=sum[j];
                sum[j]=sum[i];
                sum[i]=temp;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        printf("%d,%d,%d,%d,%d,%.2f\n",stu[i].num,stu[i].Math,stu[i].Chinese,stu[i].English,sum[i],aver[i]);
    }
    return 0;
}
