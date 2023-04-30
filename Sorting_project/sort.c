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
            j--;
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
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j+1]) {
                swap(&tab[j], &tab[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) {
            
            break;
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
void BuildHeap(int *tab, int n) {
    int parent, child, temp;
    for (int i = 1; i <= n; i++) {
        temp = tab[i - 1];
        child = i;
        parent = child / 2;
        while (parent > 0 && tab[parent - 1] < temp) {
            tab[child - 1] = tab[parent - 1];
            child = parent;
            parent /= 2;
        }
        tab[child - 1] = temp;
    }
}

void ReBuildHeap(int *tab, int last)
{
    int parent = 1;
    int l_child = 2;
    int r_child = 3;
    int bigger_child;
    int temp;

    while(l_child < last)
    {
        if(r_child < last && tab[r_child-1] > tab[l_child-1])
            bigger_child = r_child;
        else
            bigger_child = l_child;

        if(tab[bigger_child-1] <= tab[parent-1])
            break;

        temp = tab[bigger_child-1];
        tab[bigger_child-1] = tab[parent-1];
        tab[parent-1] = temp;

        parent = bigger_child;
        r_child = 2*parent;
        l_child = r_child + 1;
    }
}

void kopcowanie(int* tab,int n){
        BuildHeap(tab, n);
    for(int i = n - 1; i >= 0; i--){
        swap(&tab[0], &tab[i]);
        ReBuildHeap(tab, i+1);
    }
}

void shellInsert(int* tab, int imax, int h) {
    for (int n = 0; n < h; n++) {
        for (int i = n + h; i < imax; i += h) {
            for (int j = i - h; j >= 0 && tab[j] > tab[j + h]; j -= h) {
                swap(&tab[j + h], &tab[j]);
            }
        }
    }
}

void shell(int* tab, int n) {
        int hn = 1, h = 1;
    do {
        h = hn;
        hn = h * 3 + 1;
    } while (hn <= n);
    while (h > 0) {
        shellInsert(tab, n, h);
        h /= 3;
    }
}


void reset(int* tab, int x){
    for(int i=0; i<x; i++){
        int r = rand() % 201 - 100;
        tab[i]= r;
    }
}
int *CreateArray(int n){
    int*tab = (int *)malloc(n * sizeof(int));
    return tab;
}

void FillArray(int *tab, int n)
{
	srand((int)time(NULL));
	for (int i = 0; i < n; i++){
		tab[i] = rand() % 201 - 100;
    }
}

int* FreeArray(int* tab){

    if (tab)
	{
		free(tab);
		tab = NULL;
	}
    return NULL;
	
}
void test1(int* tab, int n){
    srand(time(NULL));
    clock_t start, end;
    double time;

    readFromFile("dataSortedIncreasing.txt",tab,n);
    start = clock();
    wstawianie(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu insert sort: %f sekund.\n", time);
    printf("\n");

    //---------------------------------------------------------------------
    readFromFile("dataSortedIncreasing.txt",tab,n);

    start = clock();
    selekcja(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu selection sort: %f sekund.\n", time);
    printf("\n");
    
    //---------------------------------------------------------------------
    readFromFile("dataSortedIncreasing.txt",tab,n);

    start = clock();
    bombel(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu bubble sort: %f sekund.\n", time);
    printf("\n");
   
    //---------------------------------------------------------------------
    
}
void test2(int *tab, int n){

    srand(time(NULL));
    clock_t start, end;
    double time;
    readFromFile("dataRandom.txt",tab,n);

    start = clock();
    quicksort(tab,0,n-1);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu quicksort: %f sekund.\n", time);
    printf("\n");

    //---------------------------------------------------------------------
    readFromFile("dataRandom.txt",tab,n);

    start = clock();
    kopcowanie(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu heap sort: %f sekund.\n", time);
    printf("\n");
    
    //---------------------------------------------------------------------
    readFromFile("dataRandom.txt",tab,n);
    
    start = clock();
    shell(tab,n);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    printf("Czas dzialania algorytmu shell sort: %f sekund.\n", time);
    printf("\n");
    
}
void readFromFile(char *filename, int *tab, int n) {
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error\n");
        return;
    }
    int cnt=0;
    int flag =0;
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &tab[i]) != 1) {
            printf("Not all numbers have been loaded\n");
            flag= 1;
            break;
        }
        cnt++;
    }
    

    fclose(fp);
    if(flag) printf("Loaded %d numbers from file '%s' (%.2f%% of %d)\n", cnt, filename,(float)cnt/n*100, n);
}

int is_array_sorted(int *array, int num_elements) {
    int i;
    for (i = 1; i < num_elements; i++) {
        if (array[i] < array[i-1]) {
            return 0;
        }
    }
    return 1;
}