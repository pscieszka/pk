#include <iostream>
#include <math.h>

void input_data(int* n, double* x)
{
    printf_s("Input n, x \n");
    int ret = scanf_s("%d%lf",n,x);
    if (ret != 2)
    {
        printf("blad!\n");
        exit(1);
    }
}
double factorial(double n) {
    if (n == 1)
        return 1;
    double sum=1;
    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;
    
}

double sum(int n,double x) {
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += pow(x, i) / factorial(i);
    }
    return sum;
}
int main()
{
    int n;
    double x;
    input_data(&n, &x);
    
    double sum2 =sum(n, x);
    printf("suma=%lf",sum2);
    
}

