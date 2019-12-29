#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
int maze[8][8]= {{1,2,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1},
    {1,1,0,0,0,1,1,1},
    {1,0,0,1,0,0,0,1},
    {1,1,1,1,0,1,1,1},
    {1,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,0,1},
    {1,1,1,1,1,1,3,1}
};
int pass[8][8]={0};
struct path
{
    int m;//地图数组的行下标
    int n;//地图数组的列下标
    struct path *next;
    struct path *prev;
};

void printmaze(int m,int n);
struct path * play(struct path *next,struct path *prev);

int main()
{
    struct path *next,*prev;
    printf("输入任意键开始寻路\n");
    getch();
    system("cls");
    play(next,prev);
    printf("祝贺你成功走出迷宫！任按一键继续。。。");
    getch();
    return 0;
}
void printmaze(int m,int n)
{
    int i,j;
    int flag=1;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(i==m&&j==n&&flag==1)
            {
                printf("＠");
                flag=0;
                continue;
            }
            switch(maze[i][j])
            {
            case 2:
            case 3:
            case 0:
                printf("  ");
                break;
            case 1:
                printf("█");
                break;
            }
        }
        printf("\n");
    }
}
//建立含有N个结点的双向链表
struct path * play(struct path *next,struct path *prev)
{
    struct path *head,*p,*pnew;
    head=(struct path *)malloc(sizeof(struct path));
    head->prev=NULL;
    head->m=0;
    head->n=1;
    p=head;
    maze[0][1]=0;
    while(1)
    {
        pnew=(struct path *)malloc(sizeof(struct path));
        system("cls");
        printmaze(p->m,p->n);
        Sleep(300);
        if(maze[p->m][p->n]==3)
        {
            return NULL;
        }
        if(maze[p->m+1][p->n]!=1&&pass[p->m+1][p->n]!=4)
        {
            pass[p->m+1][p->n]=4;
            pnew->m=p->m+1;
            pnew->n=p->n;
            p->next=pnew;
            pnew->prev=p;
            p=pnew;
            continue;
        }
        if(maze[p->m][p->n+1]!=1&&pass[p->m][p->n+1]!=4)
        {
            pass[p->m][p->n+1]=4;
            pnew->m=p->m;
            pnew->n=p->n+1;
            p->next=pnew;
            pnew->prev=p;
            p=pnew;
            continue;
        }
        if(maze[p->m][p->n-1]!=1&&pass[p->m][p->n-1]!=4)
        {
            pass[p->m][p->n-1]=4;
            pnew->m=p->m;
            pnew->n=p->n-1;
            p->next=pnew;
            pnew->prev=p;
            p=pnew;
            continue;
        }
        if(maze[p->m-1][p->n]!=1&&pass[p->m-1][p->n]!=4)
        {
            pass[p->m-1][p->n]=4;
            pnew->m=p->m-1;
            pnew->n=p->n;
            p->next=pnew;
            pnew->prev=p;
            p=pnew;
            continue;
        }
        p=p->prev;
    }
    p->next=NULL;
    return head;
}
