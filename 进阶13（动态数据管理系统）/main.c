#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct content
{
	int numcontent;
	char wordcontent[11];
}CONTENT;
typedef struct field
{
	int fieldId;
	int fieldLen;
	char fieldType;
	char fieldCaption[11];
}FIELD;
int main()
{
	int n, recordnum, ret1, ret2, sum = 0;
	int i, j;
	FIELD  *p = NULL;
	CONTENT  *ps = NULL;
	do {
		printf("请输入记录的字段数：");
		ret1 = scanf("%d", &n);
	} while (ret1 != 1);
	do {
		printf("请输入记录条数：");
		ret2=scanf("%d", &recordnum);
	} while (ret2 != 1);
	p = (FIELD *)calloc(n,sizeof(FIELD));
	ps = (CONTENT *)calloc(n*recordnum,sizeof(CONTENT));
	system("cls");
	for (i = 0;i < n;i++)
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
	for (i = 0;i < n;i++)
	{
	    if(p[i].fieldType=='s')
            sum +=p[i].fieldLen+1 ;
		else if(p[i].fieldType=='n');
            sum+=4;
	}
	for (i = 0;i < n;i++)
	{
	    if ( p[i].fieldType == 's')
            printf("字段ID:%-3d,%-11s,%-3d,%c\n",  i+1,  p[i].fieldCaption, p[i].fieldLen+1,  p[i].fieldType);
		else if ( p[i].fieldType == 'n')
            printf("字段ID:%-3d,%-11s,%-3d,%c\n",  i+1,  p[i].fieldCaption, 4,  p[i].fieldType);
	}
	printf("%d\n", sum-4);
	printf("按任意键，可以录入信息\n");
	getchar();
	system("cls");
	for (j = 0;j < recordnum;j++)
	{
		for (i = 0;i < n;i++)
		{
			printf("%s=", p[i].fieldCaption);
			if ( p[i].fieldType == 's')
			{
				scanf("%s", &ps[j*n+i].wordcontent);
			}
			else if ( p[i].fieldType == 'n')
			{
				scanf("%d", &ps[j*n+i].numcontent);
			}
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
	for (j = 0;j < recordnum;j++)
	{
		for (i = 0;i < n;i++)
		{
			printf("  %s:", p[i].fieldCaption);
			if ( p[i].fieldType == 's')
			{
				printf("%10s", ps[j*n+i].wordcontent);
			}
			else if ( p[i].fieldType == 'n')
			{
				printf("%4d", ps[j*n+i].numcontent);
			}
		}
		printf("\n");
	}
	printf("程序执行完毕!按任意键退出程序。。。\n");
	free(p);
	free(ps);
	return 0;
}
