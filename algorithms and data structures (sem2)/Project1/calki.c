#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define lp 100000
#define N 100000000

double c_od,c_do;

double f3(double x)
{
 return pow(x,5)+6*pow(x,4)+7.75*pow(x,3)-1.5*pow(x,2)+pow(x,2)-2*x;      
}      
double f4(double x) {
 return sin(2*x)-6*cos(3*x)+x*x+3;
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
 double ff=0;
 for(double i=c_od + krok; i<=c_do; i+=krok)
 {
  ff = (*f)(i);
  if(ff>MAX)
        MAX=ff;
  else if(ff<MIN)
        MIN=ff;
 }
 if(MAX > 0 && MIN > 0) 
        MIN = 0;
 else if(MAX < 0 && MIN < 0) 
        MAX = 0;
double zakres = c_do-c_od;
double pole = (MAX-MIN)*zakres;
double suma=0,No=0;
double x,y;
for(int i=0; i<N; i++)
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
suma = No/N * pole;
        return suma;
}

