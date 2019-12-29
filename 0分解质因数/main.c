#include <stdlib.h>
#include <stdio.h>
int main()
{
   int n,i;
   scanf("%d",&n);
   printf("%d=",n);
   for(i=2;i<n;i++)
   {
       if(n%i==0)
       {
           printf("%d*",i);
           n/=i;
           i--;
       }
   }
   printf("%d",n);
   return 0;
}
