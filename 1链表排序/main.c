#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head;
struct node *cur;
void create(struct node *head, int i)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    cur->next = new;
    new->val = i;
    cur = cur->next;
}

void display(struct node *head, int n)
{
    struct node *p = head->next;
    for (int i = 0; i < n; i++)
    {
        printf(" %d", p->val);
        p = p->next;
    }
}

struct node* sort(struct node* head)
{
    for(struct node* i = head->next; i != NULL; i = i->next) {
        for(struct node* j = head->next; j != NULL; j = j->next) {
            if(j->val > i->val) {
                int tmp = i->val;
                i->val = j->val;
                j->val = tmp;
            }
        }
    }
    return head;
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    cur = head;
    int n, i;
    scanf("%d", &n);
    int tmp = n;
    while (tmp--)
    {
        scanf("%d", &i);
        create(head, i);
    }
    cur->next = NULL;
    display(head, n);
    head = sort(head);
    printf("\n");
    display(head, n);
}