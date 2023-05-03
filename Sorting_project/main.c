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
    printf("Podaj wielkosc tablicy dla grupy:");
    scanf("%d",&n);
    int *tab = CreateArray(n);

    test(tab,n,"random.txt");
   
    tab = FreeArray(tab);
}