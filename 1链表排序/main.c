#include <stdio.h>
#include <stdlib.h>

void main()
{
    union bt
    {
        int nk;
        char cc[4];
    }a;
    a.nk=-17;
    printf("%d\n",a.cc[0]);
    printf("%d\n",a.cc[1]);
    printf("%d\n",a.cc[2]);
    printf("%d\n",a.cc[3]);
}
