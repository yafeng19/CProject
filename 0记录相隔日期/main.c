#include <stdio.h>
#include <stdlib.h>
int Count(int year,int month,int day);
int main()
{
    int year,month,day,d;
    scanf("%4d-%2d-%2d",&year,&month,&day);
    if(year<1990||month>12||day>31)
        printf("Invalid input");
    else
    {
        d=Count(year,month,day);
        switch(d)
        {
            case 1:printf("He is working");
                break;
            case 2:printf("He is having a rest");
                break;
        }
    }
    return 0;
}
int Count(int year,int month,int day)
{
    int a,b=0,c,i,j,count=0,sum;
    int s[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=1990;i<=year;i++)
    {
        if(year%4==0&&year%100!=0||year%400==0)
            count++;
    }
    a=365*(year-1990-count)+366*count;
    c=day;
    if(year%4==0&&year%100!=0||year%400==0)
    {
        s[1]=29;
        for(j=0;j<month;j++)
        {
            b+=s[j];
        }
    }
    else
    {
        s[1]=28;
        for(j=0;j<month;j++)
        {
            b+=s[j];
        }
    }
    sum=a+b+c;
    if(sum%5<=3&&sum%5>=1) return 1;
    else return 2;

}
