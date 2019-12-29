#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
typedef struct word
{
    char en[20];
    char ch[60];
} WORD;
int main()
{
    WORD list[N+1],temp;
    FILE *fp,*fpnew;
    char enword[20],chex[60];
    int i,j,flag=1;
    if((fp=fopen("dictionary.txt","r"))==NULL)
    {
        printf("Fail to open the file!");
    }
    for(i=0; i<N; i++)
    {
        fscanf(fp,"%s %s",list[i].en,list[i].ch);
    }
    scanf("%s %s",enword,chex);
    for(i=0; i<N; i++)
    {
        if(strcmp(list[i].en,enword)==0)
        {
            strcpy(list[i].ch,chex);
            if((fpnew=fopen("dictionarynew.txt","w"))==NULL)
            {
                printf("Fail to create the file!");
            }
            for(i=0; i<N; i++)
            {
                fprintf(fpnew,"%s %s\n",list[i].en,list[i].ch);
            }
            flag=0;
        }
    }
    if(flag)
    {
        strcpy(list[N].en,enword);
        strcpy(list[N].ch,chex);
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                if(strcmp(list[j+1].en,list[j].en)<0)
                {
                    temp=list[j+1];
                    list[j+1]=list[j];
                    list[j]=temp;
                }
            }
        }
        if((fpnew=fopen("dictionarynew.txt","w"))==NULL)
        {
            printf("Fail to create the file!");
        }
        for(i=0; i<N+1; i++)
        {
            fprintf(fpnew,"%s %s\n",list[i].en,list[i].ch);
        }
    }
    fclose(fp);
    fclose(fpnew);
    return 0;
}
