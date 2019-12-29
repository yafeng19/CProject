#define LEN sizeof(struct student)
#define NULL 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char num[11];
    char name [11];
    float score1;
    float score2;
    struct student *next;
};

struct student *create();
void display (struct student *head);

void main()
{
    struct student *head;
    head=create();
    display(head);
    exit(0);
}
struct student *create()
{
    struct student *head=NULL,*p,*tail;
    int count=0;
    while (1)
    {
        p=(struct student *)malloc(LEN);
        printf("请输入学号：");
        gets(p->num);
        if(strcmp(p->num,"\0")==0)//按回车结束时，字符数组中存的是\0
        {
            free(p);
            break;
        }
        printf("请输入姓名：");
        gets(p->name);
        printf("请输入C语言和工数的成绩，并用空格分开。输入后请按回车：");
        scanf("%f%f",&p->score1,&p->score2);
        count++;
        if(count==1)
        {
            head=p;
        }
        else
        {
            tail->next=p;
        }
        tail=p;
        getchar();
    }
    return head;
}
void display (struct student *head)
{
    struct student *p=head;
    if(p!=NULL)
    {
        printf("输入结束，刚刚输入的数据为：\n");
        printf("学号       姓名       C语言  工数  \n");
        while(p!=NULL)
        {
            printf("%-10s %-10s %-5.1f %-5.1f\n",p->num,p->name,p->score1,p->score2);
            p=p->next;
        }
        printf("程序结束！");
    }
    else
    {
        printf("未输入任何数据！");
        printf("程序结束！");
    }
}
