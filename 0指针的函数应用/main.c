#include <stdio.h>
#include <stdlib.h>
#define N 10
void findmax(int n,int num[],int score[],int *maxscore,int *maxnum);
int main()
{
    int i,n,maxscore,maxnum;//�Ȱ����������Ͷ���Ҫ��ָ��ָ��ı���
    int score[N],num[N];
    printf("How many students?\n");
    scanf("%d",&n);
    printf("Input %d nums and scores\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&num[i],&score[i]);
    }
    findmax(n,num,score,&maxscore,&maxnum);//���ε�ʱ���β�Ҫȡ��ַ
    printf("maxnum=%d,maxscore=%d",maxnum,maxscore);
    return 0;
}
void findmax(int n,int num[],int score[],int *maxscore,int *maxnum)//�������ʱΪָ��
{
    int i;
    *maxscore=score[0];//*��ʾ������
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
