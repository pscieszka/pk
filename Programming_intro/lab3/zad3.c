#include <stdio.h>

int main()
{
double a=0,b=0;
printf("Podaj a:");
scanf("%lf",&a);
printf("Podaj b:");
scanf("%lf",&b);
double iloczyn=a*b;
double iloraz=a/b;
if (b==0)
{
printf("Nie dzielimy przez 0.\n");
}
else{
printf("iloczyn=%lf\niloraz=%lf\n",iloczyn,iloraz);
}
}
