#include <stdio.h>
#include <stdlib.h>
#define N 10
void findmax(int n,int num[],int score[],int *maxscore,int *maxnum);
int main()
{
    int i,n,maxscore,maxnum;//先按照正常整型定义要用指针指向的变量
    int score[N],num[N];
    printf("How many students?\n");
    scanf("%d",&n);
    printf("Input %d nums and scores\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&num[i],&score[i]);
    }
    findmax(n,num,score,&maxscore,&maxnum);//传参的时候，形参要取地址
    printf("maxnum=%d,maxscore=%d",maxnum,maxscore);
    return 0;
}
void findmax(int n,int num[],int score[],int *maxscore,int *maxnum)//传入参数时为指针
{
    int i;
    *maxscore=score[0];//*表示解引用
    *maxnum=num[0];
    for(i=0;i<n;i++)
    {
        if(score[i]>*maxscore)
        {
            *maxscore=score[i];
            *maxnum=num[i];
        }
    }
}
