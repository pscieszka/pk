#include <stdio.h>

int main(){
int tab[9];
int x;

for(int i=0; i<10; i++){
    printf("Podaj liczbe :");
    scanf("%d",&tab[i]);
    }
int tab2[9];

for (int i=0; i<10;i++){
    tab2[i]=tab[i];
    printf("Liczba numer %d to  %d\n",i+1,tab2[i]);
}
}



