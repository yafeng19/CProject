#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct FRACTION
{
     int num; //����
     int demo;//��ĸ
};
struct COMP
{
       int real;  //ʵ��
       int imag;  //�鲿
};
union NUM
{
    double realNum;
    struct FRACTION frct;
    struct COMP comp;
};
struct
{
    union NUM num;
    int nType; //���ͱ�ʶ��1��˫��������2��������3����������������Ч
} myNum;
int main()
{
    int choice;
    union NUM a;
    struct FRACTION b;
    struct COMP c ;
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("����һ��˫��������");
        scanf("%lf",&a.realNum);
        printf("��һ��˫��������%.2f\n",a.realNum);
    }
    else if(choice==2)
    {
        printf("������Ӻͷ�ĸ��");
        scanf("%d%d",&b.num,&b.demo);
        printf("��һ��������%d/%d\n",b.num,b.demo);
    }
    else if(choice==3)
    {
        printf("����ʵ�����鲿��");
        scanf("%d%d",&c.real,&c.imag);
        printf("��һ��������%d+%di\n",c.real,c.imag);
    }
    return 0;
}
