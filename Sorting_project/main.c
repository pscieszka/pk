#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 

int main(){

    srand(time(NULL));
    clock_t start, end;
    double time;
    int x;
    printf("Podaj wielkosc tablicy:");
    scanf("%d",&x);

    int tab[x];
    
    int n = sizeof(tab)/sizeof(tab[0]);
    
    
    
    start = clock();
    bombel(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu babelkowego: %f sekund.\n", time);

    reset(tab, n);
    
    start = clock();
    wstawianie(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu przez wstawianie: %f sekund.\n", time);
   
    

    start = clock();
    selekcja(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu selekcja: %f sekund.\n", time);

    reset(tab, n);
   
    start = clock();
    quicksort(tab,0,x-1);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu quicksort: %f sekund.\n", time);

    reset(tab, n);
   
    start = clock();
    kopcowanie(tab,x);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu kopcowanie: %f sekund.\n", time);

    for(int i=0; i<n; i++){
        printf("%d,",tab[i]);
    }

}