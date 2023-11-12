#include <stdio.h>

double fibo(double x)
{
if(x==0)
{
return 0;
}
else if(x==1)
{
return 1;
}
else
{
return fibo(x-1) + fibo(x-2);
}
}
int main()
{
double x;
printf("Podaj numer znaku ciagu fib. :");
scanf("%lf",&x);
printf("%.0lf\n",fibo(x));
}
