#include <stdio.h>
#include <stdlib.h>

struct line
{
  int data;
  struct line *next;
};

struct line *create(struct line *head);
void display(struct line *head);
void deletememory(struct line *head);

void main()
{
    struct line *head;
    head=create(head);
    display(head);
    deletememory(head);
    exit(0);
}
struct line *create(struct line *head)
{

    head=(struct line *)malloc(sizeof(struct line));
    struct line *p=NULL;
    int i;
    head->next=NULL;
    p=head->next;
    for(i=0;i<9;i++)
    {
        p=(struct line *)malloc(sizeof(struct line));
        p->data=i+1;
        p->next=head->next;
        head->next=p;
    }
    return head;
};
void display(struct line *head)
{
    struct line*p=head->next;
    while(p!=NULL)
    {
        if((p->data)%2==0)
        {
            printf("%d\n",p->data);
        }
        p=p->next;
    }
}
void deletememory(struct line *head)
{
    struct line*p=head,*pr=NULL;
    while(p!=NULL)
    {
        pr=p;
        p=p->next;
        free(pr);
    }
}
