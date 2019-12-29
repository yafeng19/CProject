#include <stdio.h>
#include <stdlib.h>

int len;

//����˫������Ľڵ�
typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
}Node;

//��ʼ��һ������Ľڵ㡢
Node* create_node(void)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if(p == NULL)
    {
        printf("��̬�ڴ����ʧ�ܣ�\n");
        exit(0);
    }
    scanf("%d",&(p->data));
    p->prior = NULL;
    p->next = NULL;
    return (p);
}

//��������N������˫������
Node* create_list(int n)
{
    Node *p,*new1,*head;
    int i;
    if(n >= 1)                    //���ĸ��� >= 1 ��ʱ�������ɵ�һ�����
    {
        new1 = create_node();
        head = new1;
        p = new1;
    }
    for(i = 2;i <= n;i++)    //���ɵ�һ������Ժ�Ľ�㣬������˫������Ĺ�ϵ
    {
        new1 = create_node();
        p->next = new1;
        new1->prior = p;
        p = new1;
    }
    len = n;
    if(n >= 1)
        return (head);
    else
        return 0;
}



//����ĳ���
int len_list(int len)
{
    return len;
}

//��λ�����������λ��
Node* pos_list(Node *head,int n)
{
    int i = 1;
    Node *p;
    if(i <= n)
    {
        p = head;
        for(i = 2;i <= n;i++)
            p = p->next;
    }
    return p;
}

//�������һ������
void out_front_list(Node *head)
{
    if(head == NULL)
    {
        printf("�����������Ϣ�����������ڣ�\n");
    }
    else
    {
        Node *p;
        p = head;
        while(p != NULL)
        {
            printf(" %d",p->data);
            p = p->next;
        }
    }
}

//�������һ������
void out_reverse_list(Node *head)
{
    if(head == NULL)
    {
        printf("�����������Ϣ�����������ڣ�\n");
    }
    else
    {
        int n;
        n = len_list(len);
        Node *p;
        p = pos_list(head,n);
        while(p != NULL)
        {
            printf(" %d",p->data);
            p = p->prior;
        }
    }
}

/*//�������ͷ��������
Node* start_insert_list(Node *head)
{
    Node *p;
    p = create_node();
    p->next = head;
    head->prior = p;
    head = p;
    len++;
    return (p);
}

//�������β��������
Node* end_insert_list(Node *head)
{
    int n;
    n = len_list(len);
    Node *p,*new1;
    new1 = create_node();
    p = pos_list(head,n);
    p->next = new1;
    new1->prior = p;
    len++;
    return (head);
}

//���뵽����λ��֮ǰ
Node* insert_befor_list(Node *head)
{
    int a,newlen;
    Node *pos,*p;
    printf("������Ҫ�������λ�ã�");
    scanf("%d",&a);
    printf("������Ҫ����Ľ���ֵ��");
    newlen = len_list(len);
    if(a > newlen)
    {
        head = end_insert_list(head);
    }
    else
    {
        if(a <= 1)
        {
            head = start_insert_list(head);
        }
        else
        {
            pos = pos_list(head,a);
            p = create_node();
            pos->prior->next = p;
            p->prior = pos->prior;
            p->next = pos;
            pos->prior = p;
        }
    }
    len++;
    return (head);
}

//���뵽����λ��֮��
Node* insert_after_list(Node *head)
{
    int a,newlen;
    Node *pos,*p;
    printf("������Ҫ�������λ�ã�");
    scanf("%d",&a);
    printf("������Ҫ����Ľ���ֵ��");
    newlen = len_list(len);
    if(a >= newlen)
    {
        head = end_insert_list(head);
    }
    else
    {
        if(a < 1)
        {
            head = start_insert_list(head);
        }
        else
        {
            pos = pos_list(head,a);
            p = create_node();
            p->next = pos->next;
            pos->next->prior = p;
            pos->next = p;
            p->prior = pos;
        }
    }
    len++;
    return (head);
}
//ɾ��ͷ���
Node* delect_start_list(Node *head)
{
    Node *pos;
    pos = head;
    head = head->next;
    head->prior = NULL;
    free(pos);
    len--;
    return(head);
}

//ɾ��β���
Node* delect_end_list(Node *head)
{
    Node *p,*pos;
    int newlen;
    newlen = len_list(len);
    pos = pos_list(head,newlen);
    p = pos;
    p = p->prior;
    p->next = NULL;
    free(pos);
    len--;
    return (head);
}

//ɾ��ָ��λ�õĽڵ�
Node* delect_list(Node *head)
{
    int newlen,i;
    Node *pos;
    newlen = len_list(len);
    printf("��������ɾ������λ�ã�\n");
    scanf("%d",&i);
    if(i <= 1)
        head = delect_start_list(head);
    else if(i >=newlen)
        head = delect_end_list(head);
    else
    {
        pos =pos_list(head,i);
        pos->prior->next = pos->next;
        pos->next->prior = pos->prior;
        free(pos);
    }
    len--;
    return(head);

}
*/
int main()
{
//����������
    Node* create_node(void);               //����˫������Ľڵ�
    Node* create_list(int n);              //��������N������˫������
    int len_list(int len);                 //����ĳ���
    Node* pos_list(Node *head,int n);      //��λ�����������λ��
    Node* tail_list(Node *head);           //��ָ�붨λ�������β��
    void out_front_list(Node *head);       //�������һ������
    void out_reverse_list(Node *head);     //�������һ������
/*    Node* start_insert_list(Node *head);   //�������ͷ��������
    Node* end_insert_list(Node *head);     //�������β��������
    Node* insert_befor_list(Node *head);   //���뵽����λ��֮ǰ
    Node* insert_after_list(Node *head);   //���뵽����λ��֮��
    Node* delect_start_list(Node *head);   //ɾ��ͷ���
    Node* delect_end_list(Node *head);     //ɾ��β���
    Node* delect_list(Node *head);         //ɾ��ָ��λ�õĽڵ�
*/
    //int newlen;
    Node *head;

//    printf("������Ҫ����˫������ĳ��ȣ�\n");
    scanf("%d",&len);
//    printf("��Ϊ˫������ֵ��\n");
    head = create_list(len);
//    printf("����ĳ���Ϊ��%d\n",len = len_list(len));
//    printf("�������˫������\n");
    out_front_list(head);
    printf("\n");
//    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
//    printf("\n�������˫������\n");
    out_reverse_list(head);
/*  printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\n������������ͷ���������ֵ��\n");
    head = start_insert_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\n������������β���������ֵ��\n");
    head = end_insert_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\n���뵽����λ��֮ǰ��\n");
    head = insert_befor_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\n���뵽����λ��֮��\n");
    head = insert_after_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\nɾ��ͷ��㣺\n");
    head = delect_start_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\nɾ��β��㣺\n");
    head = delect_end_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));

    printf("\nɾ��ָ��λ�õĽ�㣺\n");
    head = delect_list(head);
    printf("����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_front_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
    printf("\n�������˫������\n");
    out_reverse_list(head);
    printf("\n����ĳ���Ϊ��%d",len = len_list(len));
*/
    return 0;
}
