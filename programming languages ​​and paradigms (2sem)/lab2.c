#include <stdio.h>
#include <math.h>

int fun_inp(int* p_i, double* p_a, char* str, char* str2){
    int k;

		printf("podaj int, double, string, string\n");

		//Wczytujemy int, double. scanf_s tu dzila dokladnie tak samo, jak i scanf z CRT.
		k = scanf("%ld%lf", p_i, p_a);
		if (k < 2)
			return 1;

		//Wczytujemy wiersz tekstowy.
		k = scanf("%s", str), scanf("%s", str2);
		if (k < 1)
			return 1;
		return 0;
}
int fun_inp2(double* a, double* b,double* c, double* d){
    int k;

		printf("podaj 4 liczby double:\n");

		k = scanf("%lf%lf%lf%lf", a,b,c,d);
		if (k < 4)
			return 1;
		return 0;
}
void stdin_clear()
	/*==============================================================
	Wyczyszczamy stdin.
	===============================================================*/
{
	int ch;
	printf("wyczyszczamy stdin:   ");
	while ((ch = getchar()) != '\n')
	{
		printf("%c", ch);
	}
	printf(" ; \n");
}
void fun_print(int i, double a, char *str, char *str2){
    printf("year: %d, score: %lf, name: %s, surname: %s, \n", i, a, str, str2);
}
int main(){
    char name[20], surname[20];
    int year;
    double score;
    fun_inp(&year, &score, name, surname);
    stdin_clear();
    fun_print(year, score, name, surname);
    double a,b,c,d;
    fun_inp2(&a,&b,&c,&d);
    stdin_clear();
    double f1,f2,f3;
    f1 = (a+b)/(c-d)-(c+d)/a+b;
    printf("f1 = %lf\n",f1);
    f2 = a - sin(b/c+d);
    printf("f2 = %lf\n",f2);
    f3 = log10(a/(b-c))+d;
    printf("f3 = %lf\n",f3);
    return 0;
}