#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int CountDigit(int number);
int main()
{
    int m,ret;
    for(m=1000;m<1112;m++)
    {
        ret=CountDigit(m);
        if(ret!=0)
            printf("%d\n",ret);
    }
    return 0;
}

int CountDigit(int number)
{
    int i,j,a[4],b[4],number0,number9;
    number9=number*9;
    number0=number;
    for (i=0;i<4;i++)
    {
        a[i]=number%10;
        number/=10;
    }
    for (j=0;j<4;j++)
    {
        b[j]=number9%10;
        number9/=10;
    }
    if((a[3]==b[0])&&(a[2]==b[1])&&(a[1]==b[2])&&(a[0]==b[3]))
        return number0;
        else return 0;
}
