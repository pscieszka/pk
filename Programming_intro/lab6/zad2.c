#include <stdio.h>

int main()
{
int x,suma=0,licznik=0;
printf("Podaj liczbe calkowita nieujemna: ");
scanf("%d",&x);
do{
int temp =x;
while(temp!=0){
temp/=10;
licznik++;
}
for(int i=0; i<licznik;i++){
int y=x;
suma+=y%10;
x=x/10;
}
printf("suma=%d\n",suma);
x=suma;
suma=0;
}
while(x>=10);
}



