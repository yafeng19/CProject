#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <cstring>
#define   MAX_LEN  10                		/* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
int   Menu(int n);
int  ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n);
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m, float  cousum[], float couaver[]);
void AverSumofEveryStudent(float score[][COURSE_NUM], int n, int m, float  stusum[STU_NUM], float stuaver[STU_NUM]);
void  SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m, int (*compare)(float a, float b));
int   Ascending(float a, float b);
int   Descending(float a, float b);
void  SwapFloat(float* x, float* y);
void  SwapLong(long* x, long* y);
void  SwapChar(char x[], char y[]);
void  AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m);
void  SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m);
void  SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m);
void  SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m);
void  StatisticAnalysis(float score[][COURSE_NUM], int n, int m);
void  PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m);

float cousum[STU_NUM], couaver[STU_NUM], stusum[COURSE_NUM],stuaver[COURSE_NUM];

int main()
{
	int ret, ntemp,n;
	printf("Input student number(n<30):\n");
	scanf("%d", &n);
	while (Menu(n) == 0);
}
int   Menu(int n)
{
	int choice,m;
	long num[STU_NUM];
	char name[STU_NUM][MAX_LEN];
	float score[STU_NUM][COURSE_NUM];

	printf(
		"Management for Students' scores\n"
		"1.Input record\n"
		"2.Caculate total and average score of every course\n"
		"3.Caculate total and average score of every student\n"
		"4.Sort in descending order by score\n"
		"5.Sort in ascending order by score\n"
		"6.Sort in ascending order by number\n"
		"7.Sort in dictionary order by name\n"
		"8.Search by number\n"
		"9.Search by name\n"
		"10.Statistic analysis\n"
		"11.List record\n"
		"0.Exit\n"
		"Please Input your choice:\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
        m=ReadScore(num, name, score, n);
		break;
	case 2:
		AverSumofEveryCourse(score, n, m, cousum, couaver);
		break;
	case 3:
		AverSumofEveryStudent(score, n, m, stusum, stuaver);
		break;
	case 4:
		SortbyScore(num, name, score, stusum, stuaver, n, m, Descending);
		break;
	case 5:
		SortbyScore(num, name, score, stusum, stuaver, n, m, Ascending);
		break;
	case 6:
		AsSortbyNum(num, name, score, stusum, stuaver, n, m);
		break;
	case 7:
		SortbyName(num, name, score, stusum, stuaver, n, m);
		break;
	case 8:
		SearchbyNum(num, name, score, stusum, stuaver, n, m);
		break;
	case 9:
		SearchbyName(num, name, score, stusum, stuaver, n, m);
		break;
	case 10:
		StatisticAnalysis(score, n, m);
		break;
	case 11:
		PrintScore(num, name, score, stusum, stuaver, n, m);
		break;
	case 0:
	{
		printf("End of program!");
		exit(0);
	}
	break;
	default:
		printf("Input error!\n");
	}
	return 0;
}
int  ReadScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], int n)
{
	int i, j, mtemp,m;
	printf("Input course number(m<=%d):\n", COURSE_NUM);
	scanf("%d", &m);
	printf("Input student's ID, name and score:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%ld%s", &num[i], &name[i]);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &score[i][j]);
		}
	}
	return m;
}
void AverSumofEveryCourse(float score[][COURSE_NUM], int n, int m, float  cousum[], float couaver[])
{
	int i, j;
	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			cousum[j] += score[i][j];
		}
		couaver[j] = cousum[j] / n;
	}
	for (j = 0; j < m; j++)
		printf("course %d:sum=%.0f,aver=%.0f\n", j + 1, cousum[j], couaver[j]);
}
void AverSumofEveryStudent(float score[][COURSE_NUM], int n, int m, float  stusum[], float stuaver[])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			stusum[i] += score[i][j];
		}
		stuaver[i] = stusum[i] / m;
	}
	for (i = 0; i < n; i++)
		printf("student %d:sum=%.0f,aver=%.0f\n", i + 1, stusum[i], stuaver[i]);
}
void  SortbyScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m,  int(*compare)(float a, float b))
{
	int i, j, k,b;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*compare)(stusum[j], stusum[k]))
			{
				k = j;
			}
		}
		if (k != i)
		{
			SwapFloat(&stusum[k], &stusum[i]);
			SwapFloat(&stuaver[k], &stuaver[i]);
			for(b=0;b<m;b++)
            {
                SwapFloat(&score[k][b],&score[i][b]);
            }
			SwapLong(&num[k], &num[i]);
			SwapChar(name[k], name[i]);
		}
	}
	if (stusum[0] < stusum[1])
		printf("Sort in ascending order by score:\n");
	else
		printf("Sort in descending order by score:\n");
	for (i = 0; i < n; i++)
	{
		printf("%ld\t%s\t", num[i], name[i]);
		for (j = 0; j < m; j++)
			printf("%.0f\t", score[i][j]);
		printf("%.0f\t%.0f\n", stusum[i], stuaver[i]);
	}
}
void  AsSortbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m)
{
	int i, j, k,b;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (num[j] < num[k])
			{
				k = j;
			}
		}
		if (k != i)
		{
			SwapFloat(&stusum[k], &stusum[i]);
			SwapFloat(&stuaver[k], &stuaver[i]);
			for(b=0;b<m;b++)
            {
                SwapFloat(&score[k][b],&score[i][b]);
            }
			SwapLong(&num[k], &num[i]);
			SwapChar(name[k], name[i]);
		}
	}
	printf("Sort in ascending order by number:\n");
	for (i = 0; i < n; i++)
	{
		printf("%ld\t%s\t", num[i], name[i]);
		for (j = 0; j < m; j++)
			printf("%.0f\t", score[i][j]);
		printf("%.0f\t%.0f\n", stusum[i], stuaver[i]);
	}
}
void  SortbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m)
{
	int i, j, k,b;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(name[j], name[k]) < 0)
			{
				k = j;
			}
		}
		if (k != i)
		{
			SwapFloat(&stusum[k], &stusum[i]);
			SwapFloat(&stuaver[k], &stuaver[i]);
			for(b=0;b<m;b++)
            {
                SwapFloat(&score[k][b],&score[i][b]);
            }
			SwapLong(&num[k], &num[i]);
			SwapChar(name[k], name[i]);
		}
	}
	printf("Sort in dictionary order by name:\n");
	for (i = 0; i < n; i++)
	{
		printf("%ld\t%s\t", num[i], name[i]);
		for (j = 0; j < m; j++)
			printf("%.0f\t", score[i][j]);
		printf("%.0f\t%.0f\n", stusum[i], stuaver[i]);
	}
}
void  SearchbyNum(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m)
{
	int i, j, search;
	printf("Input the number you want to search:\n");
	scanf("%ld", &search);
	for (i = 0;i < n;i++)
	{
		if (search == num[i])
		{
			printf("%ld\t%s\t", num[i], name[i]);
			for (j = 0; j < m; j++)
				printf("%.0f\t", score[i][j]);
			printf("%.0f\t%.0f\n", stusum[i], stuaver[i]);
			return ;
		}
	}
	printf("Not found!\n");
}
void  SearchbyName(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m)
{
	int i, j;
	char search[MAX_LEN];
	printf("Input the name you want to search:\n");
	scanf("%s", &search);
	for (i = 0;i < n;i++)
	{
		if (strcmp(search, name[i]) == 0)
		{
			printf("%ld\t%s\t", num[i], name[i]);
			for (j = 0; j < m; j++)
				printf("%.0f\t", score[i][j]);
			printf("%.0f\t%.0f\n", stusum[i], stuaver[i]);
			return ;
		}
	}
	printf("Not found!\n");
}
void  StatisticAnalysis(float score[][COURSE_NUM], int n, int m)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, i, j;
	for (j = 0;j < m;j++)
	{
	    a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		for (i = 0;i < n;i++)
		{
			if (score[i][j] < 60) a++;
			else if (score[i][j] >= 60 && score[i][j] <= 69) b++;
			else if (score[i][j] >= 70 && score[i][j] <= 79) c++;
			else if (score[i][j] >= 80 && score[i][j] <= 89) d++;
			else if (score[i][j] >= 90 && score[i][j] <= 99) e++;
			else f++;
		}
		printf("For course %d:\n", j + 1);
		printf("<60\t%d\t%.2f%%\n", a, 100.0 * a / n);
		printf("%d-%d\t%d\t%.2f%%\n", 60, 69, b, 100.0 * b / n);
		printf("%d-%d\t%d\t%.2f%%\n", 70, 79, c, 100.0 * c / n);
		printf("%d-%d\t%d\t%.2f%%\n", 80, 89, d, 100.0 * d / n);
		printf("%d-%d\t%d\t%.2f%%\n", 90, 99, e, 100.0 * e / n);
		printf("%d\t%d\t%.2f%%\n", 100, f, 100.0 * f / n);
	}

}
void  PrintScore(long num[], char name[][MAX_LEN], float score[][COURSE_NUM], float  stusum[], float stuaver[], int n, int m)
{
	int i, j, k,b;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(name[j], name[k]) < 0)
			{
				k = j;
			}
		}
		if (k != i)
		{
			SwapFloat(&stusum[k], &stusum[i]);
			SwapFloat(&stuaver[k], &stuaver[i]);
			for(b=0;b<m;b++)
            {
                SwapFloat(&score[k][b],&score[i][b]);
            }
			SwapLong(&num[k], &num[i]);
			SwapChar(name[k], name[i]);
		}
	}
	printf("Sort in dictionary order by name:\n");
	for (i = 0; i < n; i++)
	{
		printf("%ld\t%s\t", num[i], name[i]);
		for (j = 0; j < m; j++)
			printf("%.0f\t", score[i][j]);
		printf("%.0f\t%.0f\n", stusum[i], stuaver[i]);
	}
}
int   Ascending(float a, float b)
{
	return a < b;
}
int   Descending(float a, float b)
{
	return a > b;
}
void  SwapFloat(float* x, float* y)
{
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void  SwapLong(long* x, long* y)
{
	long temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void  SwapChar(char x[], char y[])
{
	char temp[MAX_LEN];
	strcpy(temp, x);
	strcpy(x,  y);
	strcpy(y, temp);
}
