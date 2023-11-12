#include <stdio.h>

int main(){
int t,s;
int tab[5]={127,131,137,139,149};
int licznik=0;
int licznik2=0;
scanf("%d",&t);
scanf("%d",&s);
char slowo[s];
int zestaw[s];
int k2;

for(int i=0; i<t;i++){
    for(int j=0; j<s;j++){
        scanf("%d",&zestaw[j]);
}

int k=-1;

do{
k++;

licznik=0;
for(int j=0; j<s;j++){
        if(zestaw[j]%tab[k] >64 && zestaw[j]%tab[k] <91)
        {
            slowo[j]=zestaw[j]%tab[k];
            licznik++;
        }
        else{
            break;
        }
}
if(licznik==s){
    licznik2++;
    k2=k;
}


}while(k!=4);
if(licznik2>1){
    printf("NIECZYTELNE\n");
}

else if(licznik==s || licznik2==1){
printf("%d ",tab[k2]);
printf("%s\n",slowo);
}

else{
    printf("NIECZYTELNE\n");
}
licznik2=0;
if(i+1!=t){
scanf("%d",&s);
char slowo[s];
int zestaw[s];
}
}
}



