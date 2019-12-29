#define LEN sizeof(struct student)
#define NULL 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    int data;
    struct student *next;
};

struct student *create();
struct student *Delete1(struct student *head);
struct student *Delete2(struct student *head);
void display (struct student *head);

void main()
{
    struct student *head;
    head=create();
    head=Delete1(head);
    head=Delete2(head);
    display(head);
    exit(0);
}
struct student *create()
{
    struct student *head=NULL,*p,*tail;
    int n,i;
    int count=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        p=(struct student *)malloc(LEN);
        scanf("%d",&p->data);
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
        p->next=NULL;
    }
    return head;
}
struct student *Delete1(struct student *head)
{
    struct student *p=head;
    head=p->next;
    free(p);
    return head;
}
struct student *Delete2(struct student *head)
{
    struct student *p=head,*pr=head;
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    pr=p;
    p=p->next;
    pr->next=NULL;
    free(p);
    return head;
}
void display (struct student *head)
{
    struct student *p=head;
    while(p!=NULL)
    {
        printf(" %d",p->data);
        p=p->next;
    }
}
