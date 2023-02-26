#include <stdio.h>
#include <stdlib.h>
int str_length(char str[]) {
    
    int count=0; 
    for (count; str[count] != '\0'; ++count);
    return count; 
}

int main(){
    FILE *plik, *plik2;
    int i;
    char x[100];
    printf("Podaj ciag znakow do zapisu w dane1.txt:");
    scanf("%s",&x);
    int y = str_length(x);
 plik=fopen("dane1","w");
    fprintf(plik,"%s",x);
 plik2=fopen("dane2","w");
 for(i=0;i<y;i++){
    char a = x[i];
    fputc(a, plik2);
 }
fclose(plik);
fclose(plik2);
printf("\nCiag znakow zostal zapisany do dane1.txt, a nastepne z pliku dane1.txt przekopiowany do dane2.txt\n");
}