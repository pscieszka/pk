#include<stdio.h>

int main(){
static int  N,M,N2,M2;
printf("Podaj  N i M dla macierzy a[N][M]\n");
scanf("%d%d",&N,&M);


printf("Podaj  N i M dla macierzy b[N][M]\n");
scanf("%d%d",&N2,&M2);


if(M!=N2){
	printf("Nie mozna pomnozyc tych macierzy\n");
	return 0;
	}
int a[N][M];
int b[N2][M2];



int i,j;
printf("Wypelnianie macierzy A\n");
for (i=0; i<N; i++){
printf("wypelnij %d wiersz\n\n",i+1);

for (j=0; j<M; j++){
printf("Podaj element nr %d\n",j+1);
scanf("%d",&a[i][j]);
}}

printf("\n\nmacierz poczatkowa A:\n");
for (i=0; i<N; i++)
{
printf("\n");
for (j=0; j<M; j++)
printf("%d ",a[i][j]);
}
printf("\n\n");

printf("Wypelnianie macierzy B\n");
for (i=0; i<N2; i++){
printf("wypelnij %d wiersz\n\n",i+1);

for (j=0; j<M2; j++){
printf("Podaj element nr %d\n",j+1);
scanf("%d",&b[i][j]);
}}

printf("\n\nmacierz poczatkowa B:\n");

for (i=0; i<N2; i++){

printf("\n");
for (j=0; j<M2; j++){
printf("%d ",b[i][j]);
}}
printf("\n\n");

int c[N][M2];
for (int i = 0; i < N; i++) {
      for (int j = 0; j < M2; j++) {
         c[i][j] = 0;
      }
 }  
for (int i = 0; i < N; i++) {
      for (int j = 0; j < M2; j++) {
         for (int k = 0; k < M; k++) {
            c[i][j] += a[i][k] * b[k][j];
         }
      }
   }

printf("\n\nmacierz A*B:\n");
for (i=0; i<N; i++)
{
printf("\n");
for (j=0; j<M2; j++)
printf("%d ",c[i][j]);
}
printf("\n"); 




 
}