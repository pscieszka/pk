#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void wstawianie(int* tab, int n){
    int j,temp;
    
    for(int i=1; i<n; i++ ){
        temp = tab[i];
        j = i - 1;
        while( j>=0 && tab[j] > temp){
            tab[j+1] = tab[j];
            j=j - 1;
        }
        tab[j+1] = temp;
    }
}


void selekcja(int* tab, int n){
    int min;
    for(int i=0; i<n-1; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(tab[j] < tab[min])
                min =j;
        }
        if(min != i){
            swap(&tab[min], &tab[i]);
            
        }
            
    }
}

void bombel(int* tab, int n){
    for(int j=0; j<n-1; j++){
        for(int i=0; i<n-j-i; i++){
            if(tab[i] > tab[i+1])
                swap(&tab[i], &tab[i+1]);
    }
    }
}

int main(){

    srand(time(NULL));
    
    int x;
    printf("Podaj wielkosc tablicy");
    scanf("%d",&x);
    int tab[x];
    for(int i=0; i<x; i++){
        int r = rand() % 100;
        tab[i]= r;
    }
    int n = sizeof(tab)/sizeof(tab[0]);
    
    wstawianie(tab,n);
    //selekcja(tab,n);
    //bombel(tab,n);
    for(int i=0; i<n; i++){
        printf("%d, ",tab[i]);
    }



}