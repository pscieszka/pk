#include <iostream>
#include <functional>
#include <vector>
#include <string>

#include <algorithm>
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
/*
4.Stwórz deklarację swojej klasy wyjątku, która będzie przechowywać kod błędu (numer) oraz jego opis.
*/

class MyException : public exception {
    const char* msg;
    int code;

public:
    MyException(const char* message,int code) : msg(message), code(code) {}

   const char* what() const override {
        return msg;
   }
   int getCode() const {
        return code;
    }
};




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
    cout << findMax([&](double x) {return b * x + a; }, 0.0, 20.0, 0.1) << endl;
    cout << findMax([=](double x) {return b * x + a; }, 0.0, 20.0, 0.1) << endl<<endl<<endl;
    

    /*
    2.Stwórz kontener, który wypełnisz danymi dowolnego typu.Następnie użyj funkcji z biblioteki standardowej find_if, aby znaleźć element z wymyślonym przez Ciebie warunkiem.
    Przykładowo, kontener może przechowywać napisy, a Ty chcesz znaleźć pierwszy, który ma w sobie 3 litery a.
    */
    const vector<string> vec = { "abc","asdsad","aaaaa","dsadasdadadadadada" };

    auto it =find_if(vec.begin(), vec.end(), [&](string str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'a') cnt++;
            if (cnt == 3) return true;
            }
        return false;
        });
    cout << *it;
    /*
     3.Stwórz program, który będzie wczytywać wartość, dopóki nie uda się jej zrzutować ze string do double.
    */
   while (true) {
        cout << "Podaj string" << endl;
        string str;
        double num;
        cin >> str;
        try {
            num = stod(str);
        }
        catch(const invalid_argument& e){
            cout << "Allocation failed: " << e.what() << '\n';
            break;
        }
    }
    /*
    5.Stwórz program rzucający Twój stworzony wyjątek.
    */
    try {
        throw MyException("custom exception",23);
    }
    catch (const MyException& e) {
        cout << "BLAD: " << e.what() <<" "<< e.getCode();
    }
    catch (...) {
        cout << "Caught exception in default block" << endl;
    }
}

