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
    
    double w=1/x,s;
    for(int i=1;i<=2*li; i+=2)
    {
        double temp=(2+i)*(pow(x,2+i));
        temp = 1/temp;
        w += temp;
    }

    return  2*w;
    
   
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
    printf("      x szereg(x) funkcja(x)\n ----------------------------\n");
    for (x=a;x<=b;x+=krok)
    {
        printf("%10.2lf %7.4lf %7.4lf\n",x,szereg(x),funkcja(x));
        printf(" ----------------------------\n\n");
    }

}