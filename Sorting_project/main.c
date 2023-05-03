#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 

int main(){

    srand(time(NULL));
    clock_t start, end;
    double time;
    int n, wybor;
    
    char file[64]; 
    printf("Podaj wielkosc tablicy (int>0):");
    scanf("%d",&n);
    if(n < 1){
        printf("Nie ma takiej opcji");
        return 0;
    }
    printf("\nPodaj nazwe pliku z danymi:");
    scanf("%s",file);
    printf("\nWybierz 0, 1.\n 0 - wypisanie posortowanych liczb przez printf \n 1 - tylko wyniki czasu dzialnia \n wybor:");
    scanf("%d",&wybor);
    if(wybor != 0 && wybor != 1 ){
        printf("Nie ma takiej opcji");
        return 0;
    }
    printf("\n");
    
    int *tab = CreateArray(n);
    test(tab,n,file,wybor);
    tab = FreeArray(tab);
}