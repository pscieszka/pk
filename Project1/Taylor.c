#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define li 100
double funkcja(double x)
{
    return log((x+1)/(x-1));
}
double szereg(double x)
{
    double s,w;
    s=x;
    w=x;
    for(int i=1;i<=li; i++)
    {
        w = 2*(1/((w*x*x)+(2*w*x*x)));
        s=s+w;
    }
    return s;
}

int main()
{
    int lp;
    double a,b,log,krok,x;
    printf("Podaj konce przedzialow i liczbe podprzedzialow\n");
    scanf("%lf %lf %d",&a,&b,&lp);
    krok=(b-a)/lp;
    printf("krok=%6.2lf\n\n\n",krok);
    printf(" ----------------------------\n\n");
    printf(" x szereg(x) funkcja(x)\n ----------------------------\n");
    for (x=a;x<=b;x+=krok)
    {
        printf("%10.2lf %7.4lf %7.4lf\n",x,szereg(x),funkcja(x));
        printf(" ----------------------------\n\n");
    }

}