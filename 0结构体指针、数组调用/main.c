#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int num;
    int score;
} STUDENT;
void inputscore(int n,STUDENT stu[]);
void findmax(int n,STUDENT *p);
int main()
{
    int n;.

    STUDENT stu[41],*p=NULL;
    printf("请输入班级人数：");
    scanf("%d",&n);
    p=stu;
    inputscore(n,p);
    findmax(n,stu);
    return 0;
}
void inputscore(int n,STUDENT *p)
{
    int i;
    printf("输入学号和成绩（空格分隔）:\n");
    for(i=0; i<n; i++,p++)
    {
        scanf("%d %d",&p[i].num,&p[i].score);
    }
}
void findmax(int n,STUDENT stu[])
{
    int i,j;
    stu[40]=stu[0];
    for(i=0; i<n; i++)
    {
        if(stu[i].score>stu[40].score)
        {
            stu[40]=stu[i];
        }
    }
    printf("分数最高的学号为%d，分数为%d\n",stu[40].num,stu[40].score);
}
