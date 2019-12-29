#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct FRACTION
{
     int num; //分子
     int demo;//分母
};
struct COMP
{
       int real;  //实部
       int imag;  //虚部
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
    int nType; //类型标识：1：双精度数、2：分数、3：虚数，其它数无效
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
        printf("输入一个双精度数：");
        scanf("%lf",&a.realNum);
        printf("是一个双精度数：%.2f\n",a.realNum);
    }
    else if(choice==2)
    {
        printf("输入分子和分母：");
        scanf("%d%d",&b.num,&b.demo);
        printf("是一个分数：%d/%d\n",b.num,b.demo);
    }
    else if(choice==3)
    {
        printf("输入实部和虚部：");
        scanf("%d%d",&c.real,&c.imag);
        printf("是一个虚数：%d+%di\n",c.real,c.imag);
    }
    return 0;
}
