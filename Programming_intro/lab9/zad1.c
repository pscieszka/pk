#include <stdio.h>

int main(){
double a[3][3];
printf("Wypelnij macierz liczbami\n");
for(int i=0; i<3; i++){
printf("Wypelnij wiersz trzema liczbami:\n");
for(int j=0; j<3;j++){
scanf("%lf",&a[i][j]);
}}
printf("Macierz przed odwroceniem\n");
for (int i=0; i<3; i++){
printf("\n\t");
for (int j=0; j<3; j++){
printf("%.0lf ",a[i][j]);
}
printf("\n");
}
int wyznacznik = a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-(a[0][2]*a[1][1]*a[2][0]+a[0][0]*a[1][2]*a[2][1]+a[0][1]*a[1][0]*a[2][2]);
if(wyznacznik==0){
printf("\nNie da sie odwrocic macierzy bo wyznaczik jest rowny zero \n");
return 0;
}
int b[3][3];
b[0][0]=a[1][1]*a[2][2]-a[1][2]*a[2][1];
b[0][1]=-1*(a[1][0]*a[2][2]-a[1][2]*a[2][0]);
b[0][2]=a[1][0]*a[2][1]-a[1][1]*a[2][0];
b[1][0]=-1*(a[0][1]*a[2][2]-a[0][2]*a[2][1]);
b[1][1]=a[0][0]*a[2][2]-a[0][2]*a[2][0];
b[1][2]=-1*(a[0][0]*a[2][1]-a[0][1]*a[2][0]);
b[2][0]=a[0][1]*a[1][2]-a[0][2]*a[1][1];
b[2][1]=-1*(a[0][0]*a[1][2]-a[0][2]*a[1][0]);
b[2][2]=a[0][0]*a[1][1]-a[0][1]*a[1][0];
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
a[i][j] = b [j][i];
a[i][j]*=1./wyznacznik;

}}
printf("Macierz po odwroceniu\n");
for (int i=0; i<3; i++){
printf("\n\t");
for (int j=0; j<3; j++){
printf("%.3lf ",a[i][j]);
}
printf("\n");
}










}

