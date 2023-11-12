#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *plik;
    int i;
    int x;

 plik=fopen("dane","w");
 for(i=0;i<5;i++){
    printf("Podaj liczbe:");
    scanf("%d",&x);
    fprintf(plik,"%d\n",x);
 }
 fclose(plik);
 plik=fopen("dane","r");
 for(i=0;i<5;i++)
 {
 fscanf(plik,"%d",&x);
 printf("%d\n",x);
 }
}

