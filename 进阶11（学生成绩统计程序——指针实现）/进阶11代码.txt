#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
	char score[4][24];
	char *p;
	int *num;
	float *Chinese_score,*Math_score,*English_score;
	double* sum;
	int i;
	printf("请依次输入学生9位数的学号、语文成绩、数学成绩、英语成绩，每一项之间用空格隔开，输入下一个同学的信息时请按回车\n");
	for(i=0;i<4;i++)
    {
        p = score[i];
        num = (int*)p;
        Chinese_score = (float*)(p + 4);
        Math_score=(float*)(p + 8);
        English_score=(float*)(p + 12);
        scanf("%d %f %f %f", num,Chinese_score,Math_score,English_score);
        sum=(double*)(p+16);
        *sum=*Chinese_score+*Math_score+*English_score;
    }
    printf("学号\t\t语文\t数学\t英语\t总分\t\n");
    for(i=0;i<4;i++)
    {
        p = score[i];
        num = (int*)p;
        Chinese_score = (float*)(p + 4);
        Math_score=(float*)(p + 8);
        English_score=(float*)(p + 12);
        sum=(double*)(p+16);
        printf("%d\t%5.2f\t%5.2f\t%5.2f\t%5.2lf\n", *num,*Chinese_score,*Math_score,*English_score,*sum);
    }
	return 0;
}
