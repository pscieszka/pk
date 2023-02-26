#include <stdio.h>

int main()
{
int tab[9];
printf("Podaj 10 liczb:");
for(int i=0; i<10;i++){
scanf("%d",&tab[i]);
}
int  temp,j;
for(int i=1; i<10;i++){
temp = tab[i];
j = i-1;
while(j>=0 && tab[j]>temp)
{
tab[j+1] = tab[j];
--j;

}
tab[j+1] = temp;
}




printf("posortowane liczby:\n");
for (int i=0; i<10; i++){
printf("%d\n",tab[i]);
}}


