#include <stdio.h>
#include <math.h>

#include <stdbool.h>

int main(){
    
    int n;
    printf("Podaj gorny zakres:");
    scanf("%d",&n);
    bool A[n];
    for(int i=0;i<n;i++)
        A[i]=true;
    for(int i=2; i<sqrt(n);i++){
        if (A[i]==true){
            for(int j=i*i; j<n;j+=i){
                
                A[j]=false;
            }
        }

    }
    for(int i=2; i<n; i++){
        if(A[i]==true){
            printf("%d, ",i);
        }
    }

}

