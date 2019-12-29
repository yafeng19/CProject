#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct winners
{
    char name[20];
    int finalScore;
    int classScore;
    char work;
    char west;
    int paper;
    int scholarship;
} WIN;

int main()
{
    WIN stu[50];
    int num,i;
    char name[20];
    printf("Input n:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        stu[i].scholarship=0;
        printf("Input name:");
        scanf("%s",&stu[i].name);
        printf("Input final score:");
        scanf("%d",&stu[i].finalScore);
        printf("Input class score:");
        scanf("%d",&stu[i].classScore);
        printf("Class cadre or not?(Y/N):");
        scanf(" %c",&stu[i].work);
        printf("Students from the West or not?(Y/N):");
        scanf(" %c",&stu[i].west);
        printf("Input the number of published papers:");
        scanf("%d",&stu[i].paper);
        if(stu[i].finalScore>80&&stu[i].paper>=1)
        {
            stu[i].scholarship+=8000;
        }
        if(stu[i].finalScore>85&&stu[i].classScore>80)
        {
            stu[i].scholarship+=4000;
        }
        if(stu[i].finalScore>90)
        {
            stu[i].scholarship+=2000;
        }
        if(stu[i].finalScore>85&&stu[i].west=='Y')
        {
            stu[i].scholarship+=1000;
        }
        if(stu[i].finalScore>80&stu[i].work=='Y')
        {
            stu[i].scholarship+=850;
        }
        printf("name:%s,scholarship:%d\n",stu[i].name,stu[i].scholarship);
    }
    int max=stu[0].scholarship,k=0;
    for(i=0;i<num;i++)
    {
        if(stu[i].scholarship>max)
        {
            max=stu[i].scholarship;
            k=i;
        }
    }
    printf("%s get the highest scholarship %d\n",stu[k].name,stu[k].scholarship);
    return 0;
}
