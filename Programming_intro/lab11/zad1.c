#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long funkcjaModulo(long long a, long long b, long long n) {
    long long x=1;
    while (b>0) {
        if (b & 1) {
            x=(x*a)%n;
        }
        a=(a*a)%n;
        b=b/2;
    }

    return x;
}
int pierwsza(unsigned long long int n, int k) {
    if (n<=1 || n==4){
        return 0;
    }
    if (n<=3){
        return 1;
    }
    unsigned long long int d=n-1;
    int s = 0;
    while (d%2==0) {
        d/=2;
        s++;
    }
    for (int i=0; i< k; i++) {
        srand(time(NULL));
        unsigned long long int a = (rand()%(n-3))+2;

        unsigned long long int x = funkcjaModulo(a,d,n);
        if (x == 1 || x == n - 1){
            continue;
        }
        for (int j=1; j<s;j++) {
            x = (x*x)% n;
            if (x ==n-1)
                break;
        }
        if (x!=n-1){
            return 0;
        }
    }
}
int main(){
    unsigned long long n;
    int k;
    printf("Podaj liczbe do sprawdzenia:");
    scanf("%u",&n);

    printf("Podaj dokladnosc testu:");
    scanf("%d",&k);

    if(pierwsza(n,k)){
        printf("TAK");
    }

    else {
        printf("NIE");
    }
    
    
}