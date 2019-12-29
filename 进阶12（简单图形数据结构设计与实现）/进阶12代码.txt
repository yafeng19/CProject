#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#define N 100
struct LINE
{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct RECTANGLE
{
    int x1;
    int y1;
    int x2;
    int y2;
};
struct CIRCLE
{
    int x1;
    int y1;
    int r;
};
struct ELLIPSE
{
    int x;
    int y;
    int a;
    int b;
};
typedef union image
{
    struct LINE line;
    struct RECTANGLE rectangle;
    struct CIRCLE circle;
    struct ELLIPSE ellipse;
} IMAGE;
int main()
{
    IMAGE gragh[N];
    char fchoice,ichoice;
    char imageis[N][20];
    int deletenum[N];
    struct LINE line;
    struct RECTANGLE rectangle;
    struct CIRCLE circle;
    struct ELLIPSE ellipse;
    int flag=1,newflag=0,i=0,j=0,k=0,count=0,countmax=0;
    char deleteID;
    while(flag==1)
    {
        system("cls");
        printf("Add/List/Delete/Quit\n");
        printf("输入首字母选择功能：\n");
        fchoice=getch();
        if(fchoice=='A'||fchoice=='a')//输入图形信息
        {
            system("cls");
            printf("Line/Rectangle/Circle/Ellipse\n");
            printf("输入首字母选择要添加的图形种类,按ESC返回：\n");
            ichoice=getch();
            if(ichoice=='L'||ichoice=='l')
            {
                system("cls");
                printf("请输入直线的两个端点坐标：x1,y1,x2,y2并按回车\n");
                scanf("%d%d%d%d",&gragh[i].line.x1,&gragh[i].line.y1,&gragh[i].line.x2,&gragh[i].line.y2);
                printf("一个直线已经被添加！按任意键继续。。。");
                getchar();
                getchar();
                flag=1;
                strcpy(imageis[i],"line");
                i++;
            }
            else if(ichoice=='R'||ichoice=='r')
            {
                system("cls");
                printf("请输入矩形的左上角和右下角坐标：x1,y1,x2,y2并按回车\n");
                scanf("%d%d%d%d",&gragh[i].rectangle.x1,&gragh[i].rectangle.y1,&gragh[i].rectangle.x2,&gragh[i].rectangle.y2);
                printf("一个矩形已经被添加！按任意键继续。。。");
                getchar();
                getchar();
                flag=1;
                strcpy(imageis[i],"rectangle");
                i++;
            }
            else if(ichoice=='C'||ichoice=='c')
            {
                system("cls");
                printf("请输入圆心坐标和半径：x1,y1,r并按回车\n");
                scanf("%d%d%d",&gragh[i].circle.x1,&gragh[i].circle.y1,&gragh[i].circle.r);
                printf("一个圆形已经被添加！按任意键继续。。。");
                getchar();
                getchar();
                flag=1;
                strcpy(imageis[i],"circle");
                i++;
            }
            else if(ichoice=='E'||ichoice=='e')
            {
                system("cls");
                printf("请输入椭圆中心坐标，半长轴和半短轴：x,y,a,b并按回车\n");
                scanf("%d%d%d%d",&gragh[i].ellipse.x,&gragh[i].ellipse.y,&gragh[i].ellipse.a,&gragh[i].ellipse.b);
                printf("一个椭圆已经被添加！按任意键继续。。。");
                getchar();
                getchar();
                flag=1;
                strcpy(imageis[i],"ellipse");
                i++;
            }
            else if(ichoice==27)
            {
                flag=1;
            }
            else
            {
                system("cls");
                printf("Invalid Input!");
                system("cls");
                flag=1;
            }
            k=i-1;
        }
        else if(fchoice=='L'||fchoice=='l')//列举图形信息
        {
            system("cls");
            for(i=0; i<=k; i++)
            {
                for(count=0; count<=countmax; count++)
                {
                    if(deletenum[count]==i)
                        i++;
                }
                if(strcmp(imageis[i],"line")==0)
                {
                    printf("ID= %d:直线：端点坐标为：x1=%d,y1=%d,x2=%d,y2=%d\n",i,gragh[i].line.x1,gragh[i].line.y1,gragh[i].line.x2,gragh[i].line.y2);
                }
                else if(strcmp(imageis[i],"rectangle")==0)
                {
                    printf("ID= %d:矩形：端点坐标为：x1=%d,y1=%d,x2=%d,y2=%d\n",i,gragh[i].rectangle.x1,gragh[i].rectangle.y1,gragh[i].rectangle.x2,gragh[i].rectangle.y2);
                }
                else if(strcmp(imageis[i],"circle")==0)
                {
                    printf("ID= %d:圆形：端点坐标为：x1=%d,y1=%d,r=%d\n",i,gragh[i].circle.x1,gragh[i].circle.y1,gragh[i].circle.r);
                }
                else if(strcmp(imageis[i],"ellipse")==0)
                {
                    printf("ID= %d:椭圆：端点坐标为：x=%d,y=%d,a=%d,b=%d\n",i,gragh[i].ellipse.x,gragh[i].ellipse.y,gragh[i].ellipse.a,gragh[i].ellipse.b);
                }
            }
            printf("按任意键继续。。。");
            getchar();
            flag=1;
        }
        else if(fchoice=='D'||fchoice=='d')//删除图形
        {
            system("cls");
            printf("输入要删除的图形的ID号或按ESC返回：");
            scanf(" %c",&deleteID);
            if(deleteID==27)
            {
                flag=1;
                system("cls");
            }
            else
            {
                for(j=0; j<=k; j++)
                {
                    if(j==deleteID-'0')
                    {
                        printf("\nID为%d的图形被删除！",deleteID-'0');
                        deletenum[count]=j;
                        count++;
                        getchar();
                        getchar();
                        flag=1;
                        newflag=1;
                    }
                }
                if(newflag!=1)
                {
                    printf("ID为%d的图形没找到！",deleteID-'0');
                    getchar();
                    getchar();
                    flag=1;
                }

            }
            countmax=count;
        }
        else if(fchoice=='Q'||fchoice=='q')//退出程序
        {
            exit(0);
        }
        else//其他非法输入
        {
            system("cls");
            printf("Invalid Input!");
            system("cls");
            flag=1;
        }
    }
    return 0;
}



