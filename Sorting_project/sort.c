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
 
void insert(int* tab, int n){
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


void selection(int* tab, int n){
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

void bubble(int* tab, int n){
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
void buildHeap(int *tab, int n) {
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

void reBuildHeap(int *tab, int last)
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

void heap(int* tab,int n){
        buildHeap(tab, n);
    for(int i = n - 1; i >= 0; i--){
        swap(&tab[0], &tab[i]);
        reBuildHeap(tab, i+1);
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


int *CreateArray(int n){
    int*tab = (int *)malloc(n * sizeof(int));
    return tab;
}

int* FreeArray(int* tab){

    if (tab)
	{
		free(tab);
		tab = NULL;
	}
    return NULL;
	
}
void test(int* tab, int n, char* file, int flag){
    void (*sort[5]) (int*, int) = {insert, selection, bubble, heap, shell};
    char* name[5] = {"insert", "selection", "bubble", "heap", "shell"};
    srand(time(NULL));
    clock_t start, end;
    double time;
    for(int i=0; i<5; i++){
        readFromFile(file,tab,n);
        start = clock();
        sort[i](tab,n);
        end = clock();
        time = difftime(end, start) / CLOCKS_PER_SEC;
        if(flag==0){
            printf("\nCzas dzialania algorytmu %s sort: %f sekund.\n",name[i], time);
            printf("\nPosortowane dane:\n");
            printArray(tab,n); 
        }
        else if(flag==1){
            printf("\nCzas dzialania algorytmu %s sort: %f sekund.\n",name[i], time);
        }
    }
    
    readFromFile(file,tab,n);
    start = clock();
    quicksort(tab,0,n-1);
    end = clock();
    time = difftime(end, start) / CLOCKS_PER_SEC;
    

    if(flag==0){
        printf("\nCzas dzialania algorytmu quicksort: %f sekund.\n", time);
        printf("\nPosortowane dane:\n");
        printArray(tab,n);
    }
    else if(flag==1){
            printf("\nCzas dzialania algorytmu quicksort sort: %f sekund.\n", time);
    }
}
void readFromFile(char *filename, int *tab, int n) {
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Nie mozna otworzyc pliku\n");
        exit(0);
        
    }
    int cnt=0;
    int flag =0;
    for (int i = 0; i < n; i++) {
        if (fscanf(fp, "%d", &tab[i]) != 1) {
            printf("Nie wszystkie liczby zostaly wczytane\n");
            flag= 1;
            break;
        }
        cnt++;
    }
    

    fclose(fp);
    if(flag) printf("Wczytano %d liczb z pliku '%s' (%.2f%% z %d)\n", cnt, filename,(float)cnt/n*100, n);
}

void printArray(int* tab, int n){
    for(int i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
}

