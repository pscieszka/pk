#include<stdio.h>
#include <string.h>

int main()
{
    int wybor=0,y,z;
    char tab[100],c;
    printf("Podaj ciag znakow(cyfry i male/duze litery bez spacji):");
    scanf("%s", tab);
    int x=strlen(tab);
    printf("1.Zakoduj:\n");
    printf("2.Odkoduj:\n");   
    printf("Wybierz 1 lub 2:");
    scanf("%d",&wybor);
    if(wybor==1){
        y=3;
        z=3;
    }
    if(wybor==2){
        y=-3+26;
        z=-3+10;
    }

  for (int i = 0; i<x; i++) {

    c = tab[i];
    if (c>96) {
        c = (c - 'a' + y) % 26 + 'a';
    }
    if (c>64 && c<91) {
        c = (c - 'A' + y) % 26 + 'A';
    }
    if (c>47 && c<58) {
        c = (c - '0' + z) % 10 + '0';
    }
    tab[i] = c;

  }
  if(wybor==1){

  printf("Zaszyfrowana wiadomosc: %s", tab);
  }
  if(wybor==2){

  printf("Odszyfrowana wiadomosc: %s", tab);
  }}
    

