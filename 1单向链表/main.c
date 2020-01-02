#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link *next;
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
    struct link *p, *pr;
    int i;
    head = (struct link *)malloc(sizeof(struct link));
    head->next = NULL;
    head->data = 1;
    pr = head;
    for (i = 2; i <= n; i++)
    {
        p = (struct link *)malloc(sizeof(struct link));
        pr->next = p; //先连接，后赋值
        pr = p;
        p->next = NULL;
        p->data = i;
    }
    return head;
}
void display(struct link *head, int n)
{
    struct link *p = head;
    int i;
    while (p != NULL)
    {
        printf("%3d", p->data);
        p = p->next;
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
