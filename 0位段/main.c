#include <stdio.h>
#include <stdlib.h>
void main()
{
    union {
        unsigned long k;
        unsigned short a[2];
    } u;
    u.k = 0x12345678;
    printf("%x,%x", u.a[0], u.a[1]);
}
