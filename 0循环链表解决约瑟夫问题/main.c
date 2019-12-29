#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}LNode,*LinkList;
void Josephus(int n, int m, int k)
{
    LinkList p = NULL, x = NULL, list = NULL;
    int i;
    for(i = 1; i <= n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));//向系统申请内存
        if (p==NULL)
        {//确保指针使用前为非空指针，当p为空指针时结束程序
            printf("分配失败！");
            exit(1);
        }
        p->data = i;//编号
        if(list == NULL)
            list = p;
        else
            x->next = p;//将x和p节点串起来
            x = p;//x指针后移
    }
    p->next = list;//建立一个循环链表
    p = list;//p指针后移
    for(i = 1; i < k; i++)
    {
        x = p;
        p = p->next;
    }            //此时p指向第1个出发点
    while(p->next != p)
    {
        for(i=1; i<m; i++)
        {
            x = p;
            p = p->next;
        }                    //p指向第m个结点，x指向第m-1个结点
       x->next = p->next;              //删除第m个结点
        printf("%d号自杀\n", p->data);         //输出一个结点编号
        free(p);                        //释放被删除结点的空间
        p = x->next;                    //p指向新的出发点
    }
    printf("最后能生存下来的为%d号\n", p->data);   //输出最后那个结点的编号
    free(p);
}
int main()
{
    int m,k,n;
    printf("请输入总人数：");
    scanf("%d",&n);
    printf("请输入从第几人报数：");
    scanf("%d",&k);
    printf("请输入间隔人数：");
    scanf("%d",&m);
    Josephus(n, m, k);
}


