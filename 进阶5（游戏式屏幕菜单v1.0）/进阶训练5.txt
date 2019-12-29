#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int flag=1;

    system("cls");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*          游标式屏幕菜单示例               *\n");
    printf("*                                           *\n");
    printf("*            >菜单项一                      *\n");
    printf("*             菜单项二                      *\n");
    printf("*             菜单项三                      *\n");
    printf("*             退出                          *\n");
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
            printf("*          游标式屏幕菜单示例               *\n");
            printf("*                                           *\n");
            printf("*            >菜单项一                      *\n");
            printf("*             菜单项二                      *\n");
            printf("*             菜单项三                      *\n");
            printf("*             退出                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13:
               {
                F1:
                system("cls");
                printf("选择了第1项菜单,按回车键返回...");
                switch(getch())
                 case 13: goto Start;break;
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
            printf("*          游标式屏幕菜单示例               *\n");
            printf("*                                           *\n");
            printf("*             菜单项一                      *\n");
            printf("*            >菜单项二                      *\n");
            printf("*             菜单项三                      *\n");
            printf("*             退出                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13:
               {
                system("cls");
                printf("选择了第2项菜单,按回车键返回...");
                switch(getch())
                 case 13: goto Start;break;
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
            printf("*          游标式屏幕菜单示例               *\n");
            printf("*                                           *\n");
            printf("*             菜单项一                      *\n");
            printf("*             菜单项二                      *\n");
            printf("*            >菜单项三                      *\n");
            printf("*             退出                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("按上下方向键改变选择的菜单项，按回车键执行选择的功能...:\n");
            switch(getch())
            {
                case 13:
               {
                system("cls");
                printf("选择了第3项菜单,按回车键返回...");
                switch(getch())
                 case 13: goto Start;break;
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
            printf("*          游标式屏幕菜单示例               *\n");
            printf("*                                           *\n");
            printf("*             菜单项一                      *\n");
            printf("*             菜单项二                      *\n");
            printf("*             菜单项三                      *\n");
            printf("*            >退出                          *\n");
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
