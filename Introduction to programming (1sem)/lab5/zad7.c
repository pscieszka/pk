#include <stdio.h>

int main(){
int a,b;
printf("Podaj pierwsza liczbe:");
scanf("%d",&a);
printf("Podaj druga liczeb:");
scanf("%d",&b);
int reszta;
while(a!=b)
{
if(a>b)
{
a=a-b;
}
else
{
b=b-a;
}
}
printf("NWD=%d\n",a);
}
