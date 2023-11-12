#include <iostream>
#include <math.h>


void input_data(int* n, double* x, double* eps)
{
    printf("Input n, x, eps \n");
    int ret = scanf_s("%d%lf%lf", n, x,eps);
    if (ret != 3)
    {
        printf("blad!\n");
        exit(1);
    }
}
double factorial(double n) {
    if (n == 1)
        return 1;
    double sum = 1;
    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;

}

double sum(int n, double x) { 
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += pow(x, i) / factorial(i);
    }
    return sum;
}
double err(double sum,int x) {
    double e = 2.7182818284590452353602874;
        return fabs(sum - pow(e, x))/fabs(pow(e, x));
}
int main()
{
    int n;
    double x;
    double eps;
    input_data(&n, &x, &eps);

    double sum2;
    //rintf("suma=%lf", sum2);
    printf("wydzial\nimie\nazwisko\n=%d\nx=%lf\neps=%d\n--------------------------------\n", n, x, eps);
    for (int i = 0;i < n;i++) {
        sum2 = sum(i, x);
        printf("|%-6d|%-10.3lf||\n", i,sum2);


    }

}
