#include <stdio.h>
#define M 10
#define N 10
void Transpose(int *a, int *at, int m, int n);
void InputMatrix(int *a, int m, int n);
void PrintMatrix(int *at, int n, int m);
int main()
{
    int s[M][N], st[N][M], m, n;
    printf("Input m, n:\n");
    scanf("%d,%d", &m, &n);
    InputMatrix(s, m, n);
    Transpose(s,st,m,n);
    printf("The transposed matrix is:\n");
    PrintMatrix(*st, n,  m);
    return 0;
}
/* �������ܣ�����m*n����a��ת�þ���at */
void Transpose(int *a, int *at, int m, int n)
{
    int i, j;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            at[j*n+i]=a[i*n+j];
        }
    }
}
/* �������ܣ�����m*n����a��ֵ */
void InputMatrix(int *a, int m, int n)
{
    int i, j;
    printf("Input %d*%d matrix:\n", m, n);
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d", &a[i*n+j]);
        }
    }
}
/* �������ܣ����n*m����at��ֵ */
void PrintMatrix(int *at, int n, int m)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            printf("%-5d", at[i*n+j]);
        }
        printf("\n");
    }
}
