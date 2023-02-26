#include<stdio.h>

double silnia(double x)

{
double iloczyn=1;
for(int i=1; i<=x;i++)

{
iloczyn=iloczyn*i;
}

return iloczyn;
}


int main()
{
double x=1;
do{
printf("Podaj x: ");
scanf("%lf",&x);
if(x==0){break;}
printf("%.0lf\n",silnia(x));
} while(x!=0);
}
