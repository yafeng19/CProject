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
    printf("������洢�ĸ�����");
    scanf("%d",&n);
    printf("���������������͵绰���ո�ָ���\n");
    for(i=0; i<n; i++)
        scanf("%s %s",&man[i].name,&man[i].num);
    getchar();
    printf("�����������Բ�ѯ�绰���룺");
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
