#include <stdio.h>
#include <stdlib.h>
struct link
{
    struct link* next;
    int data;
};

int n;
struct link*head;
struct link*create(struct link*head);
struct link*exchange(struct link*head);
void display(struct link*head);

int  main()
{
    head=create(head);
    display(head);
    head=exchange(head);
    display(head);
    return 0;
}
struct link*create(struct link*head)
{
    struct link*p,*pr;
    int i;
    scanf("%d",&n);
    head=(struct link*)malloc(sizeof(struct link*));
    head->next=NULL;
    head->data=1;
    pr=head;
    for(i=2; i<=n; i++)
    {
        p=(struct link*)malloc(sizeof(struct link*));
        pr->next=p;
        pr=p;
        p->data=i;
        p->next=NULL;
    }
    return head;
}

struct link*exchange(struct link*head)
{
    struct link*p=head;
    int i;
    if(n%2==0)
    {
        for(i=1; i<=n/2; i++)
        {
            p->data=2*i-1;
            p=p->next;
        }
        for(i=n/2+1;i<=n;i++)
        {
            p->data=(i-n/2)*2;
            p=p->next;
        }
    }
    else
    {
        for(i=1; i<=(n+1)/2; i++)
        {
            p->data=2*i-1;
            p=p->next;
        }
        for((i=n+1)/2+1;i<=n;i++)
        {
            p->data=(i-(n+1)/2)*2;
            p=p->next;
        }
    }
    return head;
}
void display(struct link*head)
{
    struct link*p=head;
    int i;
    for(i=1; i<=n; i++)
    {
        printf(" %d",p->data);
        p=p->next;
    }
    printf("\n");`
}
