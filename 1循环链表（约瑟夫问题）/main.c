#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link * next;
};
struct link * head;
struct link * create(struct link *head);
void play(struct link *head);
int main()
{
    head=create(head);
    play(head);
    return 0;
}
struct link * create(struct link *head)
{
    struct link * p,*pr;
    int i;
    head=(struct link * )malloc(sizeof(struct link * ));
    head->next=NULL;
    head->data=1;
    pr=head;
    for(i=2;i<=27;i++)
    {
        p=(struct link * )malloc(sizeof(struct link * ));
        pr->next=p;
        pr=p;
        p->data=i;
        p->next=NULL;
    }
    p->next=head;
    return head;
};
void play(struct link *head)
{
    struct link * p=head,*pr;
    while(p->data!=p->next->data)
    {
        //每隔两个人退出圈子
        p=p->next;
        pr=p;
        p=p->next;//pr记录退出圈子的上一个节点

        pr->next=p->next;
        free(p);
        p=pr->next;
    }
    printf("最后在圈中的人的序号为：%d\n",p->data);
}
