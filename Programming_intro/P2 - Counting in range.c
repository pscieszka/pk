#include<stdio.h>

int main(){
    double a,b;
    int n,licznik=0;
    double x;
    printf("Podaj a i b: ");
    scanf("%lf%lf",&a,&b);
    if(a>b){
        double temp;
        temp=b;
        b=a;
        a=temp;
    }
    printf("Podaj n: ");
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        printf("Podaj liczbe  nr. %d :",i+1);
        scanf("%lf",&x);
        if(x>=a && x<=b){
            licznik++;
        }
    }
    if(licznik==1){
        printf("W przedziale znajduje sie %d liczba z %d podanych.",licznik,n);
    }
    else{
        printf("W przedziale znajduje sie %d liczb z %d podanych.",licznik,n);
    }
}


