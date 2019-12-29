#include  <stdio.h>
#include  <stdlib.h>
void InputScore(int *p, int m, int n);
int  FindMax(int *p, int m, int n, int *pRow, int *pCol);
int main()
{
    int  *pScore, m, n, maxScore, row, col;
    printf("Input array size m,n:\n");
    scanf("%d,%d", &m, &n);
    pScore=(int *)calloc(m*n,sizeof(int)); /* ���붯̬�ڴ� */

    if (pScore == NULL)
    {
        printf("No enough memory!\n");
        exit(0);
    }
    InputScore(pScore, m, n);
    maxScore = FindMax(pScore,m,n,&row,&col);

    printf("maxScore = %d, class = %d, number = %d\n", maxScore, row+1, col+1);
    free(pScore);                                      /* �ͷŶ�̬�ڴ� */
    return 0;
}

/* �������ܣ�����m��n�ж�ά�����ֵ */
void InputScore(int *p, int m, int n)
{
    int i, j;
    printf("Input %d*%d array:\n", m, n);
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d", &p[i*n+j]);
        }
    }
}
/*  �������ܣ���������m��n�ж�ά������Ԫ�ص����ֵ����ָ�������������±�ֵ */
int  FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
    int  i, j, max = p[0];
    *pRow=0;

    *pCol=0;

    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            if (p[i*n+j]>max)
            {
                max = p[i*n+j];
                *pRow = i;       /*��¼���±�*/
                *pCol = j;             /*��¼���±�*/
            }
        }
    }
    return max;
}
