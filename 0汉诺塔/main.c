#include <stdlib.h>
#include <stdio.h>
void Hanio(int n,char c1,char c2,char c3);
void Move(char cg,char cp);

void main()
{
    int n;
    printf("Please input the number of diskes:\n");
    scanf("%d",&n);
    printf("The steps to move %d diskes:\n",n);
    Hanio(n,'A','B','C');
}
void Hanio(int n,char c1,char c2,char c3)
{
    if(n==1)
        Move(c1,c3);
    else
    {
        Hanio(n-1,c1,c3,c2);
        Move(c1,c3);
        Hanio(n-1,c2,c1,c3);
    }
}
void Move(char cg,char cp)
{
    printf("%c-->%c\n",cg,cp);
}
