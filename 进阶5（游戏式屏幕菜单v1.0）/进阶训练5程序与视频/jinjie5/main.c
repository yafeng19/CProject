#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int flag=1;

    system("cls");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*          �α�ʽ��Ļ�˵�ʾ��               *\n");
    printf("*                                           *\n");
    printf("*            >�˵���һ                      *\n");
    printf("*             �˵����                      *\n");
    printf("*             �˵�����                      *\n");
    printf("*             �˳�                          *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("�����·�����ı�ѡ��Ĳ˵�����س���ִ��ѡ��Ĺ���...:\n");
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
            printf("*          �α�ʽ��Ļ�˵�ʾ��               *\n");
            printf("*                                           *\n");
            printf("*            >�˵���һ                      *\n");
            printf("*             �˵����                      *\n");
            printf("*             �˵�����                      *\n");
            printf("*             �˳�                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("�����·�����ı�ѡ��Ĳ˵�����س���ִ��ѡ��Ĺ���...:\n");
            switch(getch())
            {
                case 13:
               {
                F1:
                system("cls");
                printf("ѡ���˵�1��˵�,���س�������...");
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
            printf("*          �α�ʽ��Ļ�˵�ʾ��               *\n");
            printf("*                                           *\n");
            printf("*             �˵���һ                      *\n");
            printf("*            >�˵����                      *\n");
            printf("*             �˵�����                      *\n");
            printf("*             �˳�                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("�����·�����ı�ѡ��Ĳ˵�����س���ִ��ѡ��Ĺ���...:\n");
            switch(getch())
            {
                case 13:
               {
                system("cls");
                printf("ѡ���˵�2��˵�,���س�������...");
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
            printf("*          �α�ʽ��Ļ�˵�ʾ��               *\n");
            printf("*                                           *\n");
            printf("*             �˵���һ                      *\n");
            printf("*             �˵����                      *\n");
            printf("*            >�˵�����                      *\n");
            printf("*             �˳�                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("�����·�����ı�ѡ��Ĳ˵�����س���ִ��ѡ��Ĺ���...:\n");
            switch(getch())
            {
                case 13:
               {
                system("cls");
                printf("ѡ���˵�3��˵�,���س�������...");
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
            printf("*          �α�ʽ��Ļ�˵�ʾ��               *\n");
            printf("*                                           *\n");
            printf("*             �˵���һ                      *\n");
            printf("*             �˵����                      *\n");
            printf("*             �˵�����                      *\n");
            printf("*            >�˳�                          *\n");
            printf("*                                           *\n");
            printf("*********************************************\n");
            printf("�����·�����ı�ѡ��Ĳ˵�����س���ִ��ѡ��Ĺ���...:\n");
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
