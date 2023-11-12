#include <stdio.h>

int main(){
double a,b,c;
printf("Podaj a:");
scanf("%lf",&a);
printf("Podaj b:");
scanf("%lf",&b);
printf("podaj c:");
scanf("%lf",&c);
double obj = a*b*c;
double pole = (a*b)*2+(a*c)*2+(b*c)*2;
printf("objetosc=%lf\npole=%lf\n",obj,pole);
}
