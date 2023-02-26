#include <stdio.h>
int main()
{
int x;
printf("podaj liczbe calkowita:");

scanf("%d",&x);

for(int i=1;i<=x+1;i++)
{
if(x%i==0)
{
printf("%d\n",i);
}
}
}


