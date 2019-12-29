#include <stdio.h>
#include <stdlib.h>
int fun(char *cs)
{
    int nk=0;
    while (*cs)
        nk=nk*10+*cs++-'0';
    return (nk);

}
int main()
{
    printf("%d\n",fun("1234"));
    return 0;
}
