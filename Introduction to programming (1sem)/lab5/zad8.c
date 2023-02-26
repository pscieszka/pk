#include <stdio.h>
#include <math.h>

int main()
{
int n;
printf("Podaj ilosc liczb do wprowadzenia:");
scanf("%d",&n);
int i;
double art=0,geo=1;

for(i=0;i<n;i++)
{
printf("Podaj liczbe:");
double x;
scanf("%lf",&x);
art=art+x;
geo=geo*x;
}

double wynik1,wynik2;
wynik1 = art/n;
wynik2 = pow(geo,1./n);
printf("Srednia artytmetyczna=%.2lf\nSrednia geometryczna=%.2lf\n",wynik1,wynik2);
}
