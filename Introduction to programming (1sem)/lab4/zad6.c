#include <stdio.h>

int main()
{
printf("Rownania maja postac a1x+b1x=c1 i a2x+b2x=c2\n");
printf("Podaj a1:");
double a1,a2,b1,b2,c1,c2;
scanf("%lf",&a1);
printf("Podaj b1:");
scanf("%lf",&b1);
printf("Podaj c1:");
scanf("%lf",&c1);
printf("Podaj a2:");
scanf("%lf",&a2);
printf("Podaj b2:");
scanf("%lf",&b2);
printf("Podaj c2:");
scanf("%lf",&c2);
double w,wx,wy;
 w = a1*b2-a2*b1;
 wx = c1*b2-c2*b1;
 wy = a1*c2-a2*c1;
    if(w==0 && wx==0 && wy==0){
    printf("Rownanie ma nieskonczenie wiele rozwiazan.");
    }
    else if(w==0 && (wx!=0 || wy!=0)){
    printf("Rownanie nie ma rozwiazan.");
    }
    else{
    double x,y;
    x = wx/w;
    y = wy/w;
    printf("Rozwiazania:\nx = %lf\ny = %lf\n",x,y);
    }
}
