#include <stdlib.h>
#include <stdio.h>
void main()
{
    int s[10],min,max,i;
    float avg;
    for(i=0;i<10;i++)
    {
        scanf("%d",&s[i]);
    }
    data_ana(s,&min,&max,&avg);
    printf("最小值：%d,最大值：%d,平均值：%f",min,max,avg);
}
void data_ana(int *s,int *min,int *max,float *avg)
{
    int i,sum=0;
    *max=*s;
    *min=*s;
    for(i=0;i<10;i++)
    {
        if(*(s+i)>*max)   *max=*(s+i);
        if(*(s+i)<*min)   *min=*(s+i);
        sum+=*(s+i);
    }
    *avg=(float)sum/10;
}
