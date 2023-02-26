#include <stdio.h>
#include <math.h>

int main()
{
double x,mi,sigma;
printf("Podaj x,mi,sigma:");
scanf("%lf\n%lf\n%lf",&x,&mi,&sigma);
double wynik=(1/(sigma*sqrt(2*M_PI)))*(pow(M_E,(-((x-mi)*(x-mi)))/(2*sigma*sigma)));
printf("Wynik=%lf",wynik);
}
