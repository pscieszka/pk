#include <stdio.h>

int palindrom(long long int x){
    int size=0;
    long long int y=x;
    while(x!=0){
        x=x/10;
        size++;
        
    }
    int tab[size-1];
    int i=0;
    while(y!=0){
        tab[i]=y%10;
        y=y/10;
        i++;
    }
    for(int i=0; i<size/2; i++){
        if(tab[i]!=tab[size-1-i]){
            return 0;
        }
        
    } 
    return 1; 
}

int main(){
    long long int x;   // W treści zadania nie było podane jaki ma być typ danych, więc dałem taki sam jak w poprzednim zadaniu
    
    printf("Podaj liczbe calkowita dodatnia (max 19 znaków): ");
    scanf("%lld",&x);
    if(palindrom(x)){
        printf("Jest palindromem\n");
    }
    else{
        printf("Nie jest palindromem\n");
    }
    
}