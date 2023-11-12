#include <stdio.h>
#include <math.h>

double f1(double x)
{
    double y;
    y=log(x)+10;
    return(y);

}

double f2(double x)
{
    double y;
    y=pow(1.5,x);
    return(y);

}

double f3(double x)
{
    double y;
    y=exp(x);
    return(y);

}

int main()
{
    double x,y;
    printf("Podaj wspolrzedne punktu (x,y)\n");
    printf("Podaj x:");
    scanf("%lf",&x);
    printf("Podaj y:");
    scanf("%lf",&y);
    if(y<f1(x) && y>f2(x) && y<f3(x))
    {
        printf("Punkt lezy w wyznaczonym obszarze.\n");
    }
     else{
        printf ("Punkt nie lezy w wyznaczonym obszarze.\n");
    }
}
