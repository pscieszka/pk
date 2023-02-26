#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *plik;
    int i;
    char x[100];
    printf("Wypelnij plik 3 liniami tekstu:\n");
    plik=fopen("dane","w");
    for(int i=0; i<3; i++){
    printf("Wpisz ciag znakow:");                            //Wczytanie liter do pliku
    scanf("%s",&x);
    fprintf(plik,"%s\n",x);
    }  
 fclose(plik);


 plik=fopen("dane","rwb");
    fseek(plik,0,SEEK_END);             //policzenie ilosci znakow  pliku
    int ilosc=ftell(plik);
 fclose(plik);


int tab[ilosc-6];
plik=fopen("dane","r");
int z =fgetc(plik);
int j=0;
do{
if(z!=10){                           //wczytanie znakow z pliku do tablicy
    tab[i]=z;
    i++;
}
z=fgetc(plik);
}while(z!=-1);
fclose(plik);


for(int i=0; i<ilosc-6; i++){
    if(tab[i]<97){              //zamiana duzych liter na male
        tab[i]+=32;
    }}


int licznik;
for(int i=97; i<123; i++){
    licznik=0;
    for(int j=0; j<ilosc-6; j++){
        if(tab[j]==i){
            licznik++;
        }                                         //zliczenie powtorzen
}
char odp = i;
if(licznik!=0){
printf("litera %c pojawila sie %d razy\n",odp,licznik);}
}
}