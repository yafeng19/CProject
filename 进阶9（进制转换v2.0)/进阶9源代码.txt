#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int B(int n);
int O(int n);
int X(int n);
void Selection(int (*Choose)());

int main()
{
    int n;
    int flag=1;
    int b,o,x;
    system("cls");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*           >十进制数转二进制数             *\n");
    printf("*            十进制数转八进制数             *\n");
    printf("*            十进制数转16进制数             *\n");
    printf("*            退出                           *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
    switch(getch())
    {
    case 13: goto F1;
    case 80: flag+=1;break;
    case 72: flag-=1;break;
    }
    Start:
    while(1)
    {
        flag%=4;
        switch(flag)
        {
        case -3:
        case 1:
            system("cls");
            printf("*********************************************\n");
            printf("*                                           *\n");
            printf("*           >十进制数转二进制数             *\n");
            printf("*            十进制数转八进制数             *\n");
            printf("*            十进制数转16进制数             *\n");
            printf("*            退出                           *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13:
               {
                F1:
                system("cls");
                printf("选择了十进制数转二进制数\n");
                Selection(B);
                getch();
                break;
               }
                case 80: flag+=1;break;
                case 72: flag-=1;break;
            }
            break;
        case -2:
        case 2:
            system("cls");
            printf("*********************************************\n");
            printf("*                                           *\n");
            printf("*            十进制数转二进制数             *\n");
            printf("*           >十进制数转八进制数             *\n");
            printf("*            十进制数转16进制数             *\n");
            printf("*            退出                           *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13:
               {
                system("cls");
                printf("选择了十进制数转八进制数\n");
                Selection(O);
                getch();
                break;
               }
                case 80: flag+=1;break;
                case 72: flag-=1;break;
            }
            break;
        case -1:
        case 3:
            system("cls");
            printf("*********************************************\n");
            printf("*                                           *\n");
            printf("*            十进制数转二进制数             *\n");
            printf("*            十进制数转八进制数             *\n");
            printf("*           >十进制数转16进制数             *\n");
            printf("*            退出                           *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13:
               {
                system("cls");
                printf("选择了十进制数转16进制数\n");
                Selection(X);
                getch();
                break;
               }
                case 80: flag+=1;break;
                case 72: flag-=1;break;
            }
            break;
        case 0:
        case 4:
            system("cls");
            printf("*********************************************\n");
            printf("*                                           *\n");
            printf("*            十进制数转二进制数             *\n");
            printf("*            十进制数转八进制数             *\n");
            printf("*            十进制数转16进制数             *\n");
            printf("*           >退出                           *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13: system("cls");exit(0);
                case 80: flag+=1;break;
                case 72: flag-=1;break;
            }
            break;
        }
    }
    return 0;
}
void Selection(int (*Choose)())
{
    int i=0,n;
    int a[32];
    printf("请输入一个十进制整数.\n");
    scanf("%d",&n);
    (*Choose)();
    while (n>0)
    {
        a[i]=n%(*Choose)();
        i=i+1;
        n=n/(*Choose)();
    }
    printf("十进制整数转换为%d进制数是:",(*Choose)());
    for(i--;i>=0;i--)
    {
        if (a[i]<=9)
            printf("%d",a[i]);
        else if (a[i]==10)
            printf("%c",65);
        else if (a[i]==11)
            printf("%c",66);
        else if (a[i]==12)
            printf("%c",67);
        else if (a[i]==13)
            printf("%c",68);
        else if (a[i]==14)
            printf("%c",69);
        else if (a[i]==15)
            printf("%c",70);
    }

}
int B(int n)
{
    return 2;
}
int O(int n)
{
    return 8;
}
int X(int n)
{
    return 16;
}

