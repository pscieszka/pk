#include<stdio.h>

int main(){
int a;
int b;
printf("Podaj a i b prostokata:");
scanf("%d%d",&a,&b);
for(int i=0; i<a;i++){
printf("\n");
	for(int j=0; j<b;j++){
	printf("*");
	}
}
printf("\n");
}


