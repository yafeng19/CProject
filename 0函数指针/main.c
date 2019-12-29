#include <stdio.h>
float Fun1(float x);
float Fun2(float x);
float Integral(float (*f)(float), float a, float b);
int main()
{
    float y1, y2;
    y1 = Integral(Fun1, 0.0, 1.0);
    y2 = Integral(Fun2, 0.0, 3.0);
    printf("y1=%f\ny2=%f\n", y1, y2);
    return 0;
}

/*  �������ܣ����㺯��1+x*x�ĺ���ֵ */
float Fun1(float x)
{
    return  1 + x * x;
}

/*  �������ܣ����㺯��x/(1+x*x)�ĺ���ֵ */
float Fun2(float x)
{
    return x / (1 + x * x);
}

/*    �������ܣ������η����㺯���Ķ����� */
float Integral(float (*f)(float), float a, float b)
{
    float s, h;
    int n = 100, i;
    s = ((*f)(a) + (*f)(b)) / 2;
    h = (b - a) / n;

    for (i=1; i<n; i++)
    {
       s +=(*f)(a + i * h);
    }
    return s * h;
}
