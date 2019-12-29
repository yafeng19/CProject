#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct content
{
    char wordcontent[11];
} CONTENT;

typedef struct field
{
    int fieldId;
    int fieldLen;
    char fieldType;
    char fieldCaption[11];
} FIELD;


int n, recordnum;
FIELD  *p = NULL;
CONTENT  *ps = NULL;
int version=19;
int sum = 0;

void search();
void create();

int main()
{
    char choice;
    while(1)
    {
        system("cls");
        printf("请按方括号中的字母选择功能：\n");
        printf("[C]reate a table,[L]ist a table exist,[Q]uit:");
        choice=getchar();
        if(choice=='C'||choice=='c')
        {
            create();
        }
        else if(choice=='L'||choice=='l')
        {
            search();
        }
        else if(choice=='Q'||choice=='q')
        {
            exit(0);
        }
    }
    return 0;
}
void create()
{
    int n, recordnum;
    int i, j;
    char filename[20];
    FILE *fp;
    sum=0;
    printf("请输入记录的字段数：");
    scanf("%d", &n);
    printf("请输入记录条数：");
    scanf("%d", &recordnum);
    p = (FIELD *)calloc(n,sizeof(FIELD));
    ps = (CONTENT *)calloc(n*recordnum,sizeof(CONTENT));
    system("cls");
    for (i = 0; i < n; i++)
    {

        printf("请输入字段名称：");
        scanf("%s", &p[i].fieldCaption);
        printf("请输入选择字段类型：int n,string s:");
        scanf(" %c", &p[i].fieldType);
        if ( p[i].fieldType == 's')
        {
            printf("输入字符串长度：");
            scanf("%d", &p[i].fieldLen);
            printf("一个字段属性输入完毕，按任意键继续。。。\n");
        }
        else if ( p[i].fieldType == 'n')
        {
            printf("一个字段属性输入完毕，按任意键继续。。。\n");
        }
    }
    getchar();
    system("cls");
    printf("已建立记录的字段属性信息：\n");
    for (i = 0; i < n; i++)
    {
        if(p[i].fieldType=='s')
            sum +=p[i].fieldLen+1 ;
        else if(p[i].fieldType=='n');
        sum+=4;
    }
    for (i = 0; i < n; i++)
    {
        if ( p[i].fieldType == 's')
            printf("字段ID:%-3d,字段名称:%-11s,字段所占字节长度:%-3d,字段类型:%c\n",  i+1,  p[i].fieldCaption, p[i].fieldLen+1,  p[i].fieldType);
        else if ( p[i].fieldType == 'n')
            printf("字段ID:%-3d,字段名称:%-11s,字段所占字节长度:%-3d,字段类型:%c\n",  i+1,  p[i].fieldCaption, 4,  p[i].fieldType);
    }
    printf("字段所占总字节长度:%d\n", sum-4);
    printf("按任意键，可以录入信息\n");
    getchar();
    system("cls");
    for (j = 0; j < recordnum; j++)
    {
        for (i = 0; i < n; i++)
        {
            printf("%s=", p[i].fieldCaption);
            // if ( p[i].fieldType == 's')
            // {
            scanf("%s", &ps[j*n+i].wordcontent);
            //  }
            /*  else if ( p[i].fieldType == 'n')
              {
                  scanf("%d", &ps[j*n+i].numcontent);
              }*/
        }
        if (j < recordnum - 1)
        {
            printf("一条记录录入完毕！按任意键继续录入，按ESC键返回\n");
            if (getch() == 27)
                break;
        }
        else
            printf("已经录入完了最后一条记录，按任意键可浏览输入的数据\n");
        getchar();
    }
    getchar();
    system("cls");
    printf("已经录入的信息：\n");
    for (j = 0; j < recordnum; j++)
    {
        for (i = 0; i < n; i++)
        {
            printf("  %s:", p[i].fieldCaption);
            //  if ( p[i].fieldType == 's')
            //  {
            printf("%10s", ps[j*n+i].wordcontent);
            // }
            /* else if ( p[i].fieldType == 'n')
             {
                 printf("%4d", ps[j*n+i].numcontent);
             }*/
        }
        printf("\n");
    }
    getchar();
    printf("请输入要创建的文件名\n");
    scanf("%s",&filename);
    if((fp=fopen(filename,"wb+"))==NULL)
    {
        printf("创建失败！");
        exit(-1);
    }


    fwrite(&version,1,1,fp);
    fwrite(&n,4,1,fp);
    fwrite(&recordnum,4,1,fp);
    fwrite(&sum,4,1,fp);
    for(i=0; i<n; i++)
    {
        fwrite(&p[i].fieldId,4,1,fp);
        fwrite(&p[i].fieldType,1,1,fp);
        fwrite(&p[i].fieldLen,4,1,fp);
        fwrite(&p[i].fieldCaption,11,1,fp);
    }
    for (j = 0; j < recordnum; j++)
    {
        for (i = 0; i < n; i++)
        {
            fwrite(&ps[j*n+i].wordcontent,11,1,fp);
        }
    }
    printf("文件%s创建成功\n",filename);
    printf("程序执行完毕!按任意键继续。。。\n");
    free(p);
    free(ps);
    fclose(fp);
    getchar();
    getchar();
}
void search()
{
    int i, j;
    char searchname[20];
    FILE *fps;
    system("cls");
    printf("请输入要浏览的文件名:\n");
    scanf("%s",&searchname);
    if((fps=fopen(searchname,"rb+"))==NULL)
    {
        printf("无此文件，查询失败！");
        exit(-1);
    }
    else
    {
        printf("以下是从该文件搜索到的信息：\n");
        fread(&version,1,1,fps);
        printf("版本号是：%d\n",version);
        fread(&n,4,1,fps);
        printf("字段数是%d\n",n);
        fread(&recordnum,4,1,fps);
        printf("记录数是%d\n",recordnum);
        fread(&sum,4,1,fps);
        printf("字段所占总字节数是%d\n",sum);
        printf("\n");

        printf("\t字段属性\n");
        for(i=0; i<n; i++)
        {
            fread(&p[i].fieldId,4,1,fps);
            printf("字段ID是%d,",i+1);
            fread(&p[i].fieldType,1,1,fps);
            printf("字段类型是%c,",p[i].fieldType);
            fread(&p[i].fieldLen,4,1,fps);
            if ( p[i].fieldType == 's')
            {
                printf("字段长度是%d,",p[i].fieldLen);
            }
            else if ( p[i].fieldType == 'n')
            {
                printf("字段长度是%d,",4);
            }
            fread(&p[i].fieldCaption,11,1,fps);
            printf("字段名称是%s\n",p[i].fieldCaption);
        }
        printf("\n");
        printf("\t记录数据\n");

        for (j = 0; j < recordnum; j++)
        {
            for (i = 0; i < n; i++)
            {
                fread(&ps[j*n+i].wordcontent,11,1,fps);
                printf("%10s:%10s ",p[i].fieldCaption,ps[j*n+i].wordcontent);
            }
            printf("\n");
        }
        printf("文件读取完毕，按任意键继续。。。");
    }
    free(p);
    free(ps);
    fclose(fps);
    getchar();
}
