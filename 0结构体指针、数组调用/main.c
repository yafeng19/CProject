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
    printf("������༶������");
    scanf("%d",&n);
    p=stu;
    inputscore(n,p);
    findmax(n,stu);
    return 0;
}
void inputscore(int n,STUDENT *p)
{
    int i;
    printf("����ѧ�źͳɼ����ո�ָ���:\n");
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
    printf("������ߵ�ѧ��Ϊ%d������Ϊ%d\n",stu[40].num,stu[40].score);
}
