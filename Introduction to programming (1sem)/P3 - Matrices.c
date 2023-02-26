#include <stdio.h>
#define BOLDRED     "\033[1m\033[31m"
#define RESET   "\033[0m"
#include <time.h>
#include <stdlib.h>



int main(){
    int W,K;
    int i,j,k;
    printf("Podaj wymiary macierzy W - wiersze,  K - kolumny.\n");
    printf("Wiersze:");
    scanf("%d",&W);
    printf("Kolumny:");
    scanf("%d",&K);
    int A[W][K];
    int wybor;
    printf("\n1.Wczytaj losowe liczby do macierzy z zakresu 0-99.\n2.Wczytaj liczby samodzielnie.\nWybierz 1 lub 2:");
    scanf("%d",&wybor);
    if(wybor==1){
        srand(time(NULL));
        int random;
        for(i=0;i<W;i++){
            for(j=0;j<K;j++){
                random= rand()%100;
                A[i][j]=random;
            }
        }

    }

    else if (wybor==2){
        for (i=0; i<W; i++){
            printf("Wczytaj wiersz %d:\n",i+1);

            for (j=0; j<K; j++){
                scanf("%d",&A[i][j]);
            }  
        }
    }
    else{
        printf("\nNie ma takiej opcji.\n");
        return 0;
    }

    printf("\nWczytana macierz:\n");
    for (i=0; i<W; i++)
    {  
        printf("\n");
            for (j=0; j<K; j++)
            if(A[i][j]>9)
                printf("%d ",A[i][j]);
            else
                printf("%d  ",A[i][j]);
    }
    printf("\n");

    int suma=0;
    
    for(i=0; i<W; i+=2){
        for(j=0; j<K;j+=2){
            if(A[i][j]%3==0){
                suma+=A[i][j];
            }
        }

    }

    printf("\nZsumowane elementy:\n");
    for (i=0; i<W; i++){  
        printf("\n");
            for (j=0; j<K; j++){
                if(A[i][j]>9){
                    if(j%2==0 && i%2==0 && A[i][j]%3==0){
                        printf( BOLDRED "%d " RESET ,A[i][j]);
                    }
                    else
                        printf("%d ",A[i][j]);
            }   
                
                else{
                    if(j%2==0 && i%2==0 && A[i][j]%3==0){
                        printf( BOLDRED "%d  " RESET ,A[i][j]);
                    }
                    else
                        printf("%d  ",A[i][j]);
                }
                }
    }
    printf("\n");
    printf("\nSuma elementów wynosi - %d\n",suma);


}



