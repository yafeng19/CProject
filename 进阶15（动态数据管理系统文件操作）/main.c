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
        printf("�밴�������е���ĸѡ���ܣ�\n");
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
    printf("�������¼���ֶ�����");
    scanf("%d", &n);
    printf("�������¼������");
    scanf("%d", &recordnum);
    p = (FIELD *)calloc(n,sizeof(FIELD));
    ps = (CONTENT *)calloc(n*recordnum,sizeof(CONTENT));
    system("cls");
    for (i = 0; i < n; i++)
    {

        printf("�������ֶ����ƣ�");
        scanf("%s", &p[i].fieldCaption);
        printf("������ѡ���ֶ����ͣ�int n,string s:");
        scanf(" %c", &p[i].fieldType);
        if ( p[i].fieldType == 's')
        {
            printf("�����ַ������ȣ�");
            scanf("%d", &p[i].fieldLen);
            printf("һ���ֶ�����������ϣ������������������\n");
        }
        else if ( p[i].fieldType == 'n')
        {
            printf("һ���ֶ�����������ϣ������������������\n");
        }
    }
    getchar();
    system("cls");
    printf("�ѽ�����¼���ֶ�������Ϣ��\n");
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
            printf("�ֶ�ID:%-3d,�ֶ�����:%-11s,�ֶ���ռ�ֽڳ���:%-3d,�ֶ�����:%c\n",  i+1,  p[i].fieldCaption, p[i].fieldLen+1,  p[i].fieldType);
        else if ( p[i].fieldType == 'n')
            printf("�ֶ�ID:%-3d,�ֶ�����:%-11s,�ֶ���ռ�ֽڳ���:%-3d,�ֶ�����:%c\n",  i+1,  p[i].fieldCaption, 4,  p[i].fieldType);
    }
    printf("�ֶ���ռ���ֽڳ���:%d\n", sum-4);
    printf("�������������¼����Ϣ\n");
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
            printf("һ����¼¼����ϣ������������¼�룬��ESC������\n");
            if (getch() == 27)
                break;
        }
        else
            printf("�Ѿ�¼���������һ����¼�����������������������\n");
        getchar();
    }
    getchar();
    system("cls");
    printf("�Ѿ�¼�����Ϣ��\n");
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
    printf("������Ҫ�������ļ���\n");
    scanf("%s",&filename);
    if((fp=fopen(filename,"wb+"))==NULL)
    {
        printf("����ʧ�ܣ�");
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
    printf("�ļ�%s�����ɹ�\n",filename);
    printf("����ִ�����!�����������������\n");
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
    printf("������Ҫ������ļ���:\n");
    scanf("%s",&searchname);
    if((fps=fopen(searchname,"rb+"))==NULL)
    {
        printf("�޴��ļ�����ѯʧ�ܣ�");
        exit(-1);
    }
    else
    {
        printf("�����ǴӸ��ļ�����������Ϣ��\n");
        fread(&version,1,1,fps);
        printf("�汾���ǣ�%d\n",version);
        fread(&n,4,1,fps);
        printf("�ֶ�����%d\n",n);
        fread(&recordnum,4,1,fps);
        printf("��¼����%d\n",recordnum);
        fread(&sum,4,1,fps);
        printf("�ֶ���ռ���ֽ�����%d\n",sum);
        printf("\n");

        printf("\t�ֶ�����\n");
        for(i=0; i<n; i++)
        {
            fread(&p[i].fieldId,4,1,fps);
            printf("�ֶ�ID��%d,",i+1);
            fread(&p[i].fieldType,1,1,fps);
            printf("�ֶ�������%c,",p[i].fieldType);
            fread(&p[i].fieldLen,4,1,fps);
            if ( p[i].fieldType == 's')
            {
                printf("�ֶγ�����%d,",p[i].fieldLen);
            }
            else if ( p[i].fieldType == 'n')
            {
                printf("�ֶγ�����%d,",4);
            }
            fread(&p[i].fieldCaption,11,1,fps);
            printf("�ֶ�������%s\n",p[i].fieldCaption);
        }
        printf("\n");
        printf("\t��¼����\n");

        for (j = 0; j < recordnum; j++)
        {
            for (i = 0; i < n; i++)
            {
                fread(&ps[j*n+i].wordcontent,11,1,fps);
                printf("%10s:%10s ",p[i].fieldCaption,ps[j*n+i].wordcontent);
            }
            printf("\n");
        }
        printf("�ļ���ȡ��ϣ������������������");
    }
    free(p);
    free(ps);
    fclose(fps);
    getchar();
}
