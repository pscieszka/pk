#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 100000

double c_od,c_do;

double f3(double x)
{
 return 0.01*pow(x,9)-0.03*pow(x,8)+0.5*pow(x,4)-12*pow(x,3)+pow(x,2)-x+25;      
}      
double f4(double x) {
 return sin(2*x)-6*cos(3*x)+3*x*x;
}


double prostokaty(double( *f)(double))
{
       double krok, p, suma=0;
       krok=(c_do-c_od)/lp;
       for(p=(2*c_od+krok)/2.0; p<c_do; p+=krok) //środki prostokątów.
               suma+=(*f)(p);
        suma*=krok;
       return suma;      
}

double trapezy(double (*f)(double))
{
        double krok, suma;
        suma = 0.5*((*f)(c_od)+(*f)(c_do));
        krok = (c_do-c_od)/lp;
        for(double p=c_od + krok; p<c_do; p+=krok)
                suma+=(*f)(p);
        suma*=krok;
        return suma;
}       
       
double mc(double(*f)(double))
{
 double krok = (c_do-c_od)/lp;
 double MAX=(*f)(c_od),MIN=(*f)(c_od);
 for(double i=c_od + krok; i<=c_do; i+=krok)
 {
  if((*f)(i)>MAX)
        MAX=(*f)(i);
  else if((*f)(i)<MIN)
        MIN=(*f)(i);
 }
 if(MAX > 0 && MIN > 0) 
        MIN = 0;
 else if(MAX < 0 && MIN < 0) 
        MAX = 0;
double zakres = c_do-c_od;
double pole = (MAX-MIN)*zakres;
double suma=0,No=0,ff=0;
for(int i=0; i<lp; i++)
{
 double x = rand();
 x = x/RAND_MAX*zakres+c_od;
 double y = rand();
 y = y/RAND_MAX*(MAX-MIN)+MIN;
 ff =(*f)(x); 

if (ff > y && y > 0 ) 
	No++;
else if (ff < y && y < 0) 
	No--;
}	
suma = No/lp *pole;
        return suma;
}

