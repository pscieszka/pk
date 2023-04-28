#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 

int main(){

    srand(time(NULL));
    clock_t start, end;
    double time;
    int n;
    printf("Podaj wielkosc tablicy:");
    scanf("%d",&n);

    int *tab = CreateArray(n);
    FillArray(tab,n);
    //tab = FreeArray(tab);
    
    
   


    
    
    
    
    
   
    // start = clock();
    // quicksort(tab,0,x-1);
    // end = clock();
    // time = difftime(end, start) / CLOCKS_PER_SEC;
    // printf("Czas dzialania algorytmu quicksort: %f sekund.\n", time);
    // printf("\n");
    // for(int i=0; i<n; i++){
    //     printf("%d,",tab[i]);
    // }
    // printf("\n");

}