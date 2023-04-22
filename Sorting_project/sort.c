#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 
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
    for(int j=0; j<n; j++){
        for(int i=0; i<n-j; i++){
            if(tab[i] > tab[i+1])
                swap(&tab[i], &tab[i+1]);
    }
    }
}

void quicksort(int* tab, int left, int right){
    
    int v=tab[(left+right)/2];
    int i,j,x;
    i=left;
    j=right;
    do
    {
        while(tab[i]<v) i++;
        while(tab[j]>v) j--;
        if(i<=j)
        {
            x=tab[i];
            tab[i]=tab[j];
            tab[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>left) quicksort(tab,left, j);
    if(i<right) quicksort(tab, i, right);
}

void kopcowanie(int* tab,int n){
}

void shell(int* tab,int n){
}

void reset(int* tab, int x){
    for(int i=0; i<x; i++){
        int r = rand() % 201 - 100;
        tab[i]= r;
    }
}
