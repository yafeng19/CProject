#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link *next;
    struct link *pre;
};
struct link *head;

void display(struct link *head, int n);
struct link *create(struct link *head, int n);
void deletememory(struct link *head);

void main()
{
    int n;
    scanf("%d", &n);
    head = create(head, n);
    display(head, n);
    deletememory(head);
    exit(0);
}
struct link *create(struct link *head, int n)
{
    struct link *p = NULL;
    struct link *pr = NULL;
    int i;
    head = (struct link *)malloc(sizeof(struct link)); //申请内存
    head->next = NULL;
    head->pre = NULL;
    head->data = 1;
    pr = head;
    for (i = 2; i <= n; i++)
    {
        p = (struct link *)malloc(sizeof(struct link));
        pr->next = p;
        p->pre = pr;
        pr = p;
        p->data = i; //先连接，再赋值
        p->next = NULL;
    }
    return head;
}
void display(struct link *head, int n)
{
    struct link *p = head;
    while (p != NULL)
    {
        printf("%3d", p->data);
        p = p->next;
    }
    printf("\n");
    while (p != NULL)
    {
        printf("%3d", p->data);
        p = p->pre;
    }
}
void deletememory(struct link *head)
{
    struct link *pr = NULL, *p = head;
    while (p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
