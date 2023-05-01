#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 

int main(){

    srand(time(NULL));
    clock_t start, end;
    double time;
    int n1,n2;
    printf("Podaj wielkosc tablicy dla grupy 1(max 10mln):");
    scanf("%d",&n1);
   // printf("Podaj wielkosc tablicy dla grupy 2(max 10mln):");
    //scanf("%d",&n2);
    FILE *f;
    for(int i =10000000; i<=10000000000; i+=10000000){
         f = fopen("result.txt", "a");
        stdout = f;
      
        printf("\n test dla n= %d \n",i);

        int *tab2 = CreateArray2(i);
        test2(tab2,i);
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