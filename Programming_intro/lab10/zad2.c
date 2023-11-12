#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *plik;
    int i;
    char x[100];
    printf("Podaj ciag znakow:");
    scanf("%s",&x);
    plik=fopen("dane","w");
    fprintf(plik,"%s",x);
 
 fclose(plik);
}