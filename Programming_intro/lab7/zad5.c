#include <stdio.h>

int main(){
int tab[9];
for(int i=0; i<10;i++){
    printf("Podaj liczbe: ");
    scanf("%d",&tab[i]);
}

for(int i=0;i<9;i++){
	for(int j=0;j<9-i;j++){
		if(tab[j]>tab[j+1]){
		    int temp=tab[j+1];
		    tab[j+1]=tab[j];
		    tab[j]=temp;
		}
    }
}
for(int i=0; i<10; i++){
    printf("%d\n",tab[i]);
}
}