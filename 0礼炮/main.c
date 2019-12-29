#include<stdio.h>
int main()
{
   int i=0,a=5,b=6,c=7,n=21,count=0;
    for(i=0;i<105;i++)
    {
         if(i%a==0||i%b==0||i%c==0)
         count++;
    }
    for(i=105;i<126;i++)
    {
         if(i%b==0||i%c==0)
         count++;
    }
    for(i=126;i<147;i++)
    {
         if(i%c==0)
         count++;
    }
    printf("n=%d",count);
    return 0;
}
