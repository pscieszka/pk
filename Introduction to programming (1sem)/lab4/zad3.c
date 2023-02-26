#include <stdio.h>

int main()
{
double a,b;
printf("Podaj liczbe a:");
scanf("%lf",&a);
printf("Podaj liczbe b:");
scanf("%lf",&b);
if(a>b)
{
double x;
x=(b/a)*100;
printf("Liczba a stanowi %lf%% liczby b\n",x);
}
else if (b>a)
{
double y;
y=(a/b)*100;
printf("Liczba b stanowi %lf%% liczby a\n",y);
}
}
