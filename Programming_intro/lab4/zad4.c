#include <stdio.h>
#include <math.h>
int main()
{
int wybor;
printf("Podaj liczbe, 1- pole kola, 2-pole trojkata, 3-pole kwadratu:");
scanf("%d",&wybor);

if(wybor==1)
{
printf("Podaj promien kola:");
double r;
scanf("%lf",&r);
double pole_kola;
pole_kola=r*r*M_PI;
printf("Pole kola=%lf\n",pole_kola);
}

else if(wybor==2)
{
printf("Podaj podstawe trojkata:");
double podstawa,wysokosc;
scanf("%lf",&podstawa);
printf("Podaj wysokosc trojakta:");
scanf("%lf",&wysokosc);
double pole_trojkata;
pole_trojkata = podstawa*wysokosc/2;
printf("Pole trojkata=%lf\n",pole_trojkata);
}

else if(wybor==3)
{
printf("Podaj dlugosc boku kwadratu:");
double bok;
scanf("%lf",&bok);
double pole_kwadratu;
pole_kwadratu=bok*bok;
printf("Pole kwadratu=%lf\n",pole_kwadratu);
}
}
