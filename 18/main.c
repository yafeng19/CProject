#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 100
typedef struct
{
    char name[20];
    char sex;
    float score[2];
    float aver;
} STUDENT;
void import(int n,STUDENT stu[]);
void outport(int n,STUDENT stu[]);
void search(int n,STUDENT stu[]);
void sortbyaver(int n,STUDENT stu[]);
void sortbyname(int n,STUDENT stu[]);
int main()
{
    int num;
    STUDENT stu[N];
    printf("请输入学生人数：\n");
    scanf("%d",&num);
    import(num,stu);
    outport(num,stu);
    search(num,stu);
    sortbyaver(num,stu);
    outport(num,stu);
    sortbyname(num,stu);
    outport(num,stu);
}
void import(int n,STUDENT stu[])
{
    int i,j;
    printf("请输入姓名、性别、两门成绩\n");
    for(i=0; i<n; i++)
    {
        float sum=0;
        scanf("%s %c",&stu[i].name,&stu[i].sex);
        for(j=0; j<2; j++)
        {
            scanf("%f",&stu[i].score[j]);
            sum+=stu[i].score[j];
        }
        stu[i].aver=sum/2;
    }
}
void outport(int n,STUDENT stu[])
{
    int i,j;
    printf("显示姓名、性别、两门成绩、平均成绩\n");
    for(i=0; i<n; i++)
    {
        printf("%s %c ",stu[i].name,stu[i].sex);
        for(j=0; j<2; j++)
        {
            printf("%f ",stu[i].score[j]);
        }
        printf("%f",stu[i].aver);
        printf("\n");
    }
}
void search(int n,STUDENT stu[])
{
    char str[20];
    int i,j;
    printf("请输入查询的学生姓名：\n");
    getchar();
    gets(str);
    for(i=0; i<n; i++)
    {
        if(strcmp(str,stu[i].name)==0)
        {
            printf("%s %c ",stu[i].name,stu[i].sex);
            for(j=0; j<2; j++)
            {
                printf("%f ",stu[i].score[j]);
            }
            printf("%f",stu[i].aver);
            printf("\n");
            return ;
        }
    }
    printf("没有找到");
}
void sortbyaver(int n,STUDENT stu[])
{
    int i,j;
    STUDENT temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(stu[i+1].aver>stu[i].aver)
            {
                temp=stu[i+1];
                stu[i+1]=stu[i];
                stu[i]=temp;
            }
        }
    }
}
void sortbyname(int n,STUDENT stu[])
{
    int i,j;
    STUDENT temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(strcmp(stu[j+1].name,stu[j].name)<0)
            {
                temp=stu[i+1];
                stu[i+1]=stu[i];
                stu[i]=temp;
            }
        }
    }
}
