#include <stdio.h>
#include <stdlib.h>


int main()
{
    char *p;
    p=(char*)malloc(20*1);
    scanf("%s%d%f",p,(int*)(p+12),(float*)(p+16));
    printf("%-12s%-3d%5.2f",p,*(int*)(p+12),*(float*)(p+16));
    return 0;
}
