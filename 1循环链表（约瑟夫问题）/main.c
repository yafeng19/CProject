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
        //ÿ���������˳�Ȧ��
        p=p->next;
        pr=p;
        p=p->next;//pr��¼�˳�Ȧ�ӵ���һ���ڵ�

        pr->next=p->next;
        free(p);
        p=pr->next;
    }
    printf("�����Ȧ�е��˵����Ϊ��%d\n",p->data);
}
