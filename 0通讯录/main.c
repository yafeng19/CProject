#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct men
{
    char name[7];
    char num[12];
} MAN;
int main()
{
    MAN man[200];
    int i,n;
    char search[7];
    printf("请输入存储的个数：");
    scanf("%d",&n);
    printf("请依次输入姓名和电话（空格分隔）\n");
    for(i=0; i<n; i++)
        scanf("%s %s",&man[i].name,&man[i].num);
    getchar();
    printf("请输入姓名以查询电话号码：");
    gets(search);
    if(strcmp(search,"\0")==0)
        for(i=0; i<n; i++)
            printf("%s %s\n",man[i].name,man[i].num);
    else
        for(i=0; i<n; i++)
            if(strcmp(man[i].name,search)==0)
                printf("%s %s\n",man[i].name,man[i].num);

    return 0;
}
