#include <stdio.h>

int main()
{
double x,y;
int z;
printf("Podaj pierwsza liczbe:");
scanf("%lf",&x);
printf("Podaj druga liczbe:");
scanf("%lf",&y);
printf("Podaj liczbe, 1 to suma, a 2 to roznica:");
scanf("%d",&z);
if(z==1)
{
double suma;
suma = x+y;
printf("Suma=%lf\n",suma);
}
else if (z==2)
{
double roznica;
roznica = x-y;
printf("Roznica=%lf\n",roznica);
}}
