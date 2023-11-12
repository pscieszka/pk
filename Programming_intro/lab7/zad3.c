#include <stdio.h>

int main(){
    long long int x;
    int size=0;
    printf("Podaj liczbe calkowita dodatnia: ");
    scanf("%lld",&x);
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
   
    for(int i=0;i<size;i++){
	    for(int j=0;j<size-1;j++){
		    if(tab[j]>tab[j+1]){
		    int temp=tab[j+1];
		    tab[j+1]=tab[j];
		    tab[j]=temp;
		}
    }
}

int count=0;
for(int i=0; i<size; i++){
	count=0;
	int x = tab[i];
	for(int j=0; j<size; j++){
		if(x==tab[j]){
			count++;
		}
	}
    if(tab[i]!=tab[i+1])
	printf("%d pojawilo sie %d razy\n",x,count);
    
	
}

}

