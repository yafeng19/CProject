#include <stdio.h>
#include <stdlib.h>
#define N 10
void InputArray(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main()
{
    int m,n,ret,pRow,pCol;//正常定义行、列指针
    int a[N][N]={0};
    int *p=*a;//把a的首地址给指针p//
    printf("Input m,n:\n");
    scanf("%d,%d",&m,&n);
    InputArray(a,m,n);//a数组作为实参，可以取代指针p的位置
    ret=FindMax(a,m,n,&pRow,&pCol);//访问行、列指针
    printf("max=%d,row=%d,col=%d\n",ret,pRow,pCol);//直接使用行、列指针
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
            scanf("%d",p+i*N+j);//指针数组使用方法
        }
    }
}
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
    *pRow=0;//初始化行、列指针
    *pCol=0;
    int i,j;
    int max=*p;//将指针p即数组a的首地址赋给max
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(*(p+i*N+j)>max)
            {
                max=*(p+i*N+j);//对地址操作
                *pRow=i;
                *pCol=j;
            }
        }
    }
    return max;
}
