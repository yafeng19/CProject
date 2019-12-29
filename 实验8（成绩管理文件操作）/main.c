#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int num;
    char stunum[10];
    int score[5];
    int sum;
    float aver;
}STUDENT;
int main()
{
    FILE *fp1,*fp2;
    STUDENT stu[10];
    int i,j;
    if((fp1=fopen("stRecord1.txt","r"))==NULL)
    {
        printf("Fail!");
        exit(0);
    }
    for(i=0;i<10;i++)
    {
        fscanf(fp1,"%d",&stu[i].num);
        fscanf(fp1,"%s",&stu[i].stunum);
        for(j=0;j<5;j++)
        {
            fscanf(fp1,"%d",&stu[i].score[j]);
        }
    }
    for(i=0;i<10;i++)
    {
        stu[i].sum=0;
        stu[i].aver=0;
        for(j=0;j<5;j++)
        {
            stu[i].sum+=stu[i].score[j];
        }
        stu[i].aver=stu[i].sum/5.0;
    }
    if((fp2=fopen("stRecord2.txt","w"))==NULL)
    {
        printf("Fail!");
        exit(0);
    }
    fprintf(fp2,"序号\t学号\t\t总分\t平均分\n");
    for(i=0;i<10;i++)
    {
        fprintf(fp2,"%d\t",stu[i].num);
        fprintf(fp2,"%s\t",stu[i].stunum);
        fprintf(fp2,"%d\t",stu[i].sum);
        fprintf(fp2,"%.2f\n",stu[i].aver);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
