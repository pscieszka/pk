#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *plik;
    int i;
    char x[100];
    printf("Wypelnij plik 3 liniami tekstu:\n");
    plik=fopen("dane","w");
    for(int i=0; i<3; i++){
    printf("Wpisz ciag znakow:");
    scanf("%s",&x);
    fprintf(plik,"%s\n",x);
    }
    
 fclose(plik);

 plik=fopen("dane","rwb");
    fseek(plik,0,SEEK_END);
    int ilosc=ftell(plik);
    printf("Ilosc znakow= %d\n",ilosc-6); // -6 bo \n to 10 w ascii czyli kazda nowa linia dodaje 2 znaki czyli musi byc ilosc -= ilosc_linii*2 
 fclose(plik);

}