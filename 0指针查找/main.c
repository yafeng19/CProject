#include <stdio.h>
int FindMax(int a[], int n, int *pMaxPos);
int FindMin(int a[], int n, int *pMinPos);
int main()
{
    int a[10], maxValue, maxPos, minValue, minPos, i;
    printf("Input 10 numbers:");
    for (i=0; i<10; i++)
    {
        scanf("%d", &a[i]);             // 输入10个数
    }

    maxValue = FindMax(a, 10, &maxPos);  // 找最大值及其所在下标位置
    minValue = FindMin(a, 10, &minPos);  // 找最小值及其所在下标位置
    printf("max=%d,pos=%d\n", maxValue, maxPos);
    printf("min=%d,pos=%d\n", minValue, minPos);
    return 0;
}

//函数功能：求有n个元素的整型数组a中的最大值及其所在下标位置，函数返回最大值
int FindMax(int a[], int n, int *pMaxPos)
{
    int i, max;
    max = a[0];             //假设a[0]为最大值
    *pMaxPos = 0;           //假设最大值在数组中的下标位置为0

    for (i=1; i<n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            *pMaxPos = i;     //pMaxPos指向最大值数组元素的下标位置
        }
    }
    return max ;
}

//函数功能：求有n个元素的整型数组a中的最小值及其所在下标位置，函数返回最小值
int FindMin(int a[], int n, int *pMinPos)
{
    int i, min;
    min = a[0];              //假设a[0]为最小
    *pMinPos = 0;            //假设最小值在数组中的下标位置为0

    for (i=1; i<10; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            *pMinPos = i;  //pMinPos指向最小值数组元素的下标位置
        }
    }
    return min ;
}
