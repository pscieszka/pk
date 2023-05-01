#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 
int* CreateArray2(int n) {
int *arr = malloc(sizeof(int) * n);
for (int i = 0; i < n; i++) {
arr[i] = rand() % 201 - 100;
}
return arr;
}
int main(){

    srand(time(NULL));
    clock_t start, end;
    double time;
    int n1,n2;
    printf("Podaj wielkosc tablicy dla grupy 1(max 10mln):");
    scanf("%d",&n1);
   // printf("Podaj wielkosc tablicy dla grupy 2(max 10mln):");
    //scanf("%d",&n2);
    for(int i =10000000; i<=10000000000; i+=10000000){
        FILE *f = freopen("output.txt", "a", stdout);
      
        printf("\n test dla n= %d \n",i);

        int *tab = CreateArray2(i);
    
    clock_t start, end;
    double time;
    //readFromFile("dataRandom.txt",tab,n);

    start = clock();
    quicksort(tab,0,i-1);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu quicksort: %f sekund.\n", time);
    printf("\n");

    //---------------------------------------------------------------------
    // readFromFile("dataRandom.txt",tab,n);

    start = clock();
    kopcowanie(tab,i);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu heap sort: %f sekund.\n", time);
    printf("\n");
    
    //---------------------------------------------------------------------
    //readFromFile("dataRandom.txt",tab,n);
    
    start = clock();
    shell(tab,i);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu shell sort: %f sekund.\n", time);
    printf("\n");
        //test2(tab,i);
        fclose(f);
        
    }
    
    //tab = FreeArray(tab);

   // int *tab2 = CreateArray(n2);
    //test2(tab2,n2);
   // tab2 = FreeArray(tab2);
    
  

    
    
    
    
    
   
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