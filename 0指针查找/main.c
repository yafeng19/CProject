#include <stdio.h>
int FindMax(int a[], int n, int *pMaxPos);
int FindMin(int a[], int n, int *pMinPos);
int main()
{
    int a[10], maxValue, maxPos, minValue, minPos, i;
    printf("Input 10 numbers:");
    for (i=0; i<10; i++)
    {
        scanf("%d", &a[i]);             // ����10����
    }

    maxValue = FindMax(a, 10, &maxPos);  // �����ֵ���������±�λ��
    minValue = FindMin(a, 10, &minPos);  // ����Сֵ���������±�λ��
    printf("max=%d,pos=%d\n", maxValue, maxPos);
    printf("min=%d,pos=%d\n", minValue, minPos);
    return 0;
}

//�������ܣ�����n��Ԫ�ص���������a�е����ֵ���������±�λ�ã������������ֵ
int FindMax(int a[], int n, int *pMaxPos)
{
    int i, max;
    max = a[0];             //����a[0]Ϊ���ֵ
    *pMaxPos = 0;           //�������ֵ�������е��±�λ��Ϊ0

    for (i=1; i<n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            *pMaxPos = i;     //pMaxPosָ�����ֵ����Ԫ�ص��±�λ��
        }
    }
    return max ;
}

//�������ܣ�����n��Ԫ�ص���������a�е���Сֵ���������±�λ�ã�����������Сֵ
int FindMin(int a[], int n, int *pMinPos)
{
    int i, min;
    min = a[0];              //����a[0]Ϊ��С
    *pMinPos = 0;            //������Сֵ�������е��±�λ��Ϊ0

    for (i=1; i<10; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            *pMinPos = i;  //pMinPosָ����Сֵ����Ԫ�ص��±�λ��
        }
    }
    return min ;
}
