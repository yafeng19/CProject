#include <stdio.h>
#include <stdlib.h>
typedef struct score
{
    int num;
    int Math;
    int Chinese;
    int English;
    int sum;
    float aver;
}SCORE;
int main()
{
    SCORE stu[4];//包含三条数据和一条临时储存数据
    int i,j;
    for(i=0;i<3;i++)
    {
        scanf("%d%d%d%d",&stu[i].num,&stu[i].Math,&stu[i].Chinese,&stu[i].English);
        stu[i].sum=stu[i].Math+stu[i].Chinese+stu[i].English;
        stu[i].aver=(float)(stu[i].sum)/3;
    }
    for(i=0;i<2;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(stu[j].sum>stu[i].sum)
            {
                stu[3]=stu[j];
                stu[j]=stu[i];
                stu[i]=stu[3];
            }
        }
    }
    for(i=0;i<3;i++)
    {
        printf("%d,%d,%d,%d,%d,%.2f\n",stu[i].num,stu[i].Math,stu[i].Chinese,stu[i].English,stu[i].sum,stu[i].aver);
    }
    return 0;
}
