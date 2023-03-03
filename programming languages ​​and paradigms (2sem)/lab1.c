#include "stdio.h"
#include "windows.h"
int main(int argc, char* argv[])
{
int i;
long l;
unsigned long ul;
float f;
double d1,d2;
//Input data
printf("Podaj 3 liczby calkowite\n");
scanf("%d",&i);
scanf("%ld", &l);
scanf("%u", &ul);
printf("Podaj 3 liczby rzeczywiste\n");
scanf("%f", &f);
scanf("%lf%lf", &d1, &d2);
//Output data
printf("Liczby calkowite\n---------------------\n");
printf("int |%d|\t\td\n", 1);
printf("i1 |%10d|\t\t10d\n", i1);
printf("i1 |%u|\t\tu\n", i1);
printf("i2 |%-10d|\t\t-10d\n", i2);
printf("s1 |%010hd|\t\t010hd\n", s1);
printf("s1 |%010hu|\t\t010hu\n", s1);
printf("l1 |%+10ld|\t\t+10ld\n", l1);
//printf("i1 |%-010d|\t\t-010d\n", i1);
printf("\nLiczby rzeczywiste\n---------------------\n");
printf("zz |%f|\t\tf\n", zz);
printf("xx |%10.5f|\t\t10.5f\n", xx);
printf("qq |%-+10.5lf|\t\t-+10.5f\n", qq);
printf("qq |%10.3e|\t\t10.3e\n", qq);
printf("\nLiczba typu double\n---------------------\n");
printf("dd |%-10.5lf|\t\t-10.5lf\n", dd);
printf("dd |%10.3le|\t\t10.3le\n", dd);
printf("\nTabela\n------------------------------\n");
for(int it=0; it<10; ++it)
{
 dd = 100.0*(it+1);
 printf("|%10d|%20.8lf|%+20.8le|\n", it, dd, dd);
}
int ch;
while((ch = getchar()) != EOF);
return 0;
}