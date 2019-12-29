#include <stdlib.h>
#include <stdio.h>

void Sort1(int n,int a[]);
void Sort2(int n,int a[]);
void Sort3(int n,int a[]);

int main()
{
    int n,i;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Sort1(n,a);
    printf("\n");
    Sort2(n,a);
    printf("\n");
    Sort3(n,a);
    return 0;
}
void Sort1(int n,int a[])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("Ωªªª≈≈–Ú∑®£∫\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void Sort2(int n,int a[])
{
    int i,j,k,temp;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    printf("—°‘Ò≈≈–Ú∑®£∫\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void Sort3(int n,int a[])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j+1]>a[j])
            {
                temp-a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("√∞≈›≈≈–Ú∑®£∫\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
