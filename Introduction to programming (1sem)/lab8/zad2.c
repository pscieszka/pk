#include <stdio.h>

int main()
{

int tab[9];
int temp;
printf("Podaj 10 liczb:");
for(int i=0;i<10;i++)
{
scanf("%d",&tab[i]);
}

for(int i=0;i<10;i++)
{
int k=i;
for(int j=i+1;j<10;j++)
{
	if(tab[j]<tab[k]){
	k=j;
    }
}
temp=tab[k];
tab[k]=tab[i];
tab[i]=temp;
}

printf("Posortowane liczby:\n");
for(int i=0;i<10;i++){
printf("%d\n",tab[i]);
}
}