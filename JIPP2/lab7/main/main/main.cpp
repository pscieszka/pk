#include <iostream>
#include <functional>
using namespace std;
/*
1.Stwórz funkcję wyszukującą maksimum dla przesłanego równania. Równanie powinno zostać przekazane za pomocą wyrażenia lambda.
(lambda(double), start x, end x, krok - wszystko typu double, zwraca double).
(jeżeli start = 1, end = 1.5, a krok = 0.2, to dla 1.5 nie trzeba sprawdzać).
*/
double findMax(function<double(double)>eq, double start, double end, double krok) {
    double max = eq(start);
    for (double i = start + krok; i <= end; i += krok) {
        if (eq(i) > max) {
            max = eq(i);
        }
    }
    return max;
}
int main()
{
    /*
    a)Przetestuj działanie dla kilku równań.
    */
    auto eq1 = [](double x) { return -5*x * x + 2 * x + 7; };
    cout << findMax(eq1, 0.0, 20.0, 0.1)<<endl;
    cout << findMax([](double x) {return pow(x, 3) * 5 + 3 * x * x + 5 - 4 * x; }, 0.0, 20.0, 0.1) << endl;
    cout << findMax([](double x) {return sin(x*x); }, 0.0, 20.0, 0.1) << endl;
    /*
    b)Przetestuj działanie dla równań z przesłanymi dodatkowymi wartościami przez przechwytywanie nazw (captures).
    */
    double a = 5.5;
    double b = 55.5;
    cout << findMax([a,b](double x) {return b*sin(x * x)+a; }, 0.0, 20.0, 0.1) << endl;

}


