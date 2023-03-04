#include <stdio.h>

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
printf("int           |%d|%-12d|%12d|\n", i,i,i);
printf("long          |%d|%-14ld|%+14ld|\n", l,l,l);
printf("unsigned long |%d|%-14ld|%14ld|\n", ul,ul,ul);
printf("Liczby rzeczywiste\n---------------------\n");
printf("float         |%3.4f|%-14.3f|%1.4e|%+14.4e|\n", f,f,f,f);
printf("double        |%3.4lf|%3.4lf|%3.4lf|\n", d1,d1,d1);
printf("double        |%3.4lf|%3.4lf|%3.4lf|\n", d2,d2,d2);
int ch;
while((ch = getchar()) != EOF);
return 0;
}