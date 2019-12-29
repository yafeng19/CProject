#include  <stdio.h>
typedef struct clock
{
    int hour;
    int minute;
    int second;
}CLOCK;

/* �������ܣ�ʱ���֡���ʱ��ĸ��� */
void Update(CLOCK *t)
{
    static long m = 1;
    t->hour = m / 3600;
    t->minute = (m - 3600 * t->hour) / 60;
    t->second = m % 60;
    m++;
    if (t->hour == 24)  m = 1;
}

/* �������ܣ�ʱ���֡���ʱ�����ʾ */
void Display(CLOCK *t)
{
    printf("%2d:%2d:%2d\r", t->hour, t->minute, t->second);
}

/* �������ܣ�ģ���ӳ�1���ʱ�� */
void Delay(void)
{
    long t;
    for (t=0; t<50000000; t++)
        {
            /* ѭ����Ϊ������ѭ��������ʱ���� */
        }
}

int main()
{
    long i;
    CLOCK myclock;
    myclock.hour = myclock.minute = myclock.second = 0;
    for (i=0; i<100000; i++)  /* ����ѭ��������ʱ�����е�ʱ�� */
    {
        Update(&myclock);          /* ʱ��ֵ���� */
        Display(&myclock);          /* ʱ����ʾ */
        Delay();                     /* ģ����ʱ1�� */
    }
    return 0;
}
