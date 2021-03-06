#include  <stdio.h>
typedef struct clock
{
    int hour;
    int minute;
    int second;
}CLOCK;

/* 函数功能：时、分、秒时间的更新 */
void Update(CLOCK *t)
{
    static long m = 1;
    t->hour = m / 3600;
    t->minute = (m - 3600 * t->hour) / 60;
    t->second = m % 60;
    m++;
    if (t->hour == 24)  m = 1;
}

/* 函数功能：时、分、秒时间的显示 */
void Display(CLOCK *t)
{
    printf("%2d:%2d:%2d\r", t->hour, t->minute, t->second);
}

/* 函数功能：模拟延迟1秒的时间 */
void Delay(void)
{
    long t;
    for (t=0; t<50000000; t++)
        {
            /* 循环体为空语句的循环，起延时作用 */
        }
}

int main()
{
    long i;
    CLOCK myclock;
    myclock.hour = myclock.minute = myclock.second = 0;
    for (i=0; i<100000; i++)  /* 利用循环，控制时钟运行的时间 */
    {
        Update(&myclock);          /* 时钟值更新 */
        Display(&myclock);          /* 时间显示 */
        Delay();                     /* 模拟延时1秒 */
    }
    return 0;
}
