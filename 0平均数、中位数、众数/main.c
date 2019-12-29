#include <stdio.h>
#include <stdlib.h>
void InputNumber(int num[]);
int MeanValue(int num[]);
int MedianValue(int num[]);
int ModeValue(int num[]);
int main()
{
    int num[40];
    int mean,median,mode;
    printf("Input the feedbacks of 40 students:\n");
    InputNumber(num);
    mean=MeanValue(num);
    median=MedianValue(num);
    mode=ModeValue(num);
    printf("Mean value=%d\n",mean);
    printf("Median value=%d\n",median);
    printf("Mode value=%d\n",mode);
    return 0;
}
void InputNumber(int num[])
{
    int i;
    for(i=0;i<40;i++)
    {
        scanf("%d",&num[i]);
    }
}
int MeanValue(int num[])
{
    int sum=0,mean=0,i;
    for(i=0;i<40;i++)
    {
        sum+=num[i];
    }
    mean=sum/40;
    return mean;
}
int MedianValue(int num[])
{
    int i,j,k,temp,median;
    for(i=0;i<39;i++)
    {
        k=i;
        for(j=i+1;j<40;j++)
        {
            if(num[j]>num[k])
                k=j;
        }
        if(k!=i)
        {
            temp=num[i];
            num[i]=num[k];
            num[k]=temp;
        }
    }
    median=(num[19]+num[20])/2;
    return median;
}
int ModeValue(int num[])
{
    int i,j,max,mode;
    int count[11]={0};
    MedianValue(num);
    for(i=0;i<40;i++)
    {
        if(num[i]==num[i+1])
        {
            count[num[i]]++;
        }
    }
    for(j=1;j<11;j++)
    {
        if(count[j]!=0)
            count[j]++;
    }
    max=count[1];
    for(j=1;j<11;j++)
    {
        if(count[j]>max)
        {
            max=count[j];
            mode=j;
        }
    }
    return mode;
}
