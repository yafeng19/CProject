#include <stdio.h>
#include <stdlib.h>
#define N 10
void InputArray(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main()
{
    int m,n,ret,pRow,pCol;//���������С���ָ��
    int a[N][N]={0};
    int *p=*a;//��a���׵�ַ��ָ��p//
    printf("Input m,n:\n");
    scanf("%d,%d",&m,&n);
    InputArray(a,m,n);//a������Ϊʵ�Σ�����ȡ��ָ��p��λ��
    ret=FindMax(a,m,n,&pRow,&pCol);//�����С���ָ��
    printf("max=%d,row=%d,col=%d\n",ret,pRow,pCol);//ֱ��ʹ���С���ָ��
    return 0;
}
void InputArray(int *p, int m, int n)
{
    int i,j;
    printf("Input %d*%d array:\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",p+i*N+j);//ָ������ʹ�÷���
        }
    }
}
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
    *pRow=0;//��ʼ���С���ָ��
    *pCol=0;
    int i,j;
    int max=*p;//��ָ��p������a���׵�ַ����max
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(*(p+i*N+j)>max)
            {
                max=*(p+i*N+j);//�Ե�ַ����
                *pRow=i;
                *pCol=j;
            }
        }
    }
    return max;
}
