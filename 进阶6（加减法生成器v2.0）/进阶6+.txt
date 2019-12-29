#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int add(int a,int b);
int sub(int a,int b);
void ins(int a,int b);
void exi(int a,int b);

int count1=0,count2=0,wrong1=0,wrong2=0;
    int choice,answer;
    float accuracy;
    int i,j;
int main()
{
    srand ((unsigned)time(NULL));
    int a=rand()%10,b=rand()%10,c;

    printf("10以内加减法辅助教学程序\n");
    printf("*****************************\n");
    printf("*****************************\n");
    printf("**                         **\n");
    printf("**       1 加法练习        **\n");
    printf("**       2 减法练习        **\n");
    printf("**       3 程序说明        **\n");
    printf("**       4 退出程序        **\n");
    printf("**                         **\n");
    printf("*****************************\n");
    printf("*****************************\n");
    printf("输入菜单项前的数字，选择功能，如数字超出菜单中的范围将显示0：\n");
    scanf("%d",&choice);
    system("cls");
    if (choice<1||choice>4)
    {
        system("cls");
        printf("选择了功能0");
    }
    else
    {
        switch(choice)
        {
        case 1:
            accuracy=add(a,b);
            printf("答题正确率为%f%%",accuracy);
            break;
        case 2:
            accuracy=sub(a,b);
            printf("答题正确率为%f%%",accuracy);
            break;
        case 3:
            ins(a,b);
            break;
        case 4:
            exi(a,b);
            break;
        }
    }
    getch();
}
int add(int a,int b)
{
    int i,c;
    for (i=1;i<=5;i++)
            {
                srand ((unsigned)time(NULL));
                int a=rand()%10,b=rand()%10;
                if(a>=b)
                {
                    c=a-b;
                    a=b+c;
                    printf("%d+%d=",b,c);
                    scanf("%d",&answer);
                    if (answer==b+c) count1++;
                    else
                    {
                        wrong1=0;
                        while (answer!=b+c)
                        {
                            wrong1++;
                            while (getchar()!='\n');
                            printf("%d+%d=",b,c);
                            scanf("%d",&answer);
                            if(wrong1==4)
                            {
                                printf("您已答错5次，此题正确答案为%d\n",b+c);
                                goto flag1;
                            }
                        }
                     }
                }
                else
                {
                    c=b-a;
                    b=a+c;
                    printf("%d+%d=",a,c);
                    scanf("%d",&answer);
                    if (answer==a+c) count1++;
                    else
                    {
                        wrong1=0;
                        while (answer!=a+c)
                        {
                            wrong1++;
                            while (getchar()!='\n');
                            printf("%d+%d=",a,c);
                            scanf("%d",&answer);
                            if(wrong1==4)
                            {
                                printf("您已答错5次，此题正确答案为%d",a+c);
                                goto flag1;
                            }
                        }
                     }
                }
            }
            flag1:
            accuracy=count1/5.0*100;
            return accuracy;
}
int sub(int a,int b)
{
    int j,c;
    for (j=1;j<=5;j++)
            {
                srand ((unsigned)time(NULL));
                int a=rand()%10,b=rand()%10;
                if(a>=b)
                {
                    c=a-b;
                    printf("%d-%d=",a,b);
                    scanf("%d",&answer);
                    if (answer==a-b) count2++;
                    else
                    {
                        wrong2=0;
                        while (answer!=a-b)
                        {
                            wrong2++;
                            while (getchar()!='\n');
                            printf("%d-%d=",a,b);
                            scanf("%d",&answer);
                            if(wrong2==4)
                            {
                                printf("您已答错5次，此题正确答案为%d\n",a-b);
                                goto flag2;
                            }
                        }
                     }
                }
                else
                {
                    c=b-a;
                    printf("%d-%d=",b,a);
                    scanf("%d",&answer);
                    if (answer==b-a) count2++;
                    else
                    {
                        wrong2=0;
                        while (answer!=b-a)
                        {
                            wrong2++;
                            while (getchar()!='\n');
                            printf("%d-%d=",b,a);
                            scanf("%d",&answer);
                            if(wrong2==4)
                            {
                                printf("您已答错5次，此题正确答案为%d",b-a);
                                goto flag2;
                            }
                        }
                     }
                }
            }
            flag2:
            accuracy=count2/5.0*100;
            return accuracy;
}
void ins(int a,int b)
{
    printf("程序说明");
}
void exi(int a,int b)
{
    exit(0);
}
