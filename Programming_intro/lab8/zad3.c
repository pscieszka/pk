#include <stdio.h>
#include <string.h>

int main(){
char tab[100];
int x;
printf("Podaj wyraz:");
gets(tab);

x=strlen(tab);

for(int i=x-1;i>=0;i--)
printf("%c",tab[i]);
printf("\n");
}