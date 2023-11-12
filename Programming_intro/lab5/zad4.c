#include<stdio.h>
int main()
{
int x,y=0;
printf("Podaj liczbe do sprawdzenia:");
scanf("%d",&x);
for(int i=2;i<x;i++)
{
if(x%i==0)
{
y=i;
}
}
if(y!=0){
printf("Nie jest pierwsza\n");}
else
{
printf("Jest pierwsza\n");
}
}
