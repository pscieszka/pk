#include <iostream>
#include <vector>
using namespace std;
template <typename T>
T mini(T a, T b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

template <typename T>
T maxi(T a, T b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}
template <typename T>
int find(vector<T> vec, T x) {
    for (int i = 0; i < vec.size(); i++) {
        if (x == vec[i]) {
            return i;
        }
    }
    return -1;
}

template <typename T1, typename T2, typename T3>
class Triple {
    T1 a;
    T2 b;
    T3 c;
public:
    Triple();
    Triple(T1 a, T2 b, T3 c) :a(a), b(b), c(c){};
    T1 getFirst() { return a; };
    T2 getSecond() { return b; };
    T3 getThird() { return c; };
    void setFirst(T1 a) { this->a = a; };
    void setSecond(T2 b) { this->b = b; };
    void setThird(T3 c) { this->c = c; };

};
template <typename T,unsigned size>
class MyArray {
    T tab[size];
public:
    MyArray();
    void setValueOn(unsigned index, T val) {
        try {
            tab[index] = val;
        }
        catch (out_of_range) {
            cout << "out of range" << endl;
        }
    }
    T getValue(unsigned index) {
        try {

            return tab[index];
        }
        catch (out_of_range) {
            cout << "out of range" << endl;
        }
    }


};


int main()
{
    vector<int> vec = { 1,2,3,4,5,6,1 };
    cout << find(vec, 2);
    Triple<int, double, char> t(1, 2.5, 'c');
    cout << "   " << t.getSecond() << "   ";
    MyArray<int,10> a;
    a.setValueOn(5, 10);
   
}

/*
Stwórz klasę MyArray, która będzie tworzyć tablice dla elementów dowolnego typu.
Wielkość tablicy powinna być przekazywana przez parametr szablonu. Klasa powinna być zgodna z zasadą RAII. Powinna posiadać metody:

setValueOn(index, wartość) - ustawianie wartości na podanym indeksie z wyrzucaniem wyjątku out_of_range
getValoue(index) - pobieranie wartości spod indeksu z wyrzucaniem wyjątku out_of_range
tylko konstruktor bezparametryczny
*/
//Stwórz funkcję min, max, które będą wykorzystywać mechanizm szablonów. Funkcja przyjmuje 2 argumenty i zwraca wartość.
//Stwórz funkcję find, która jako parametr przyjmuje vector
//dowolnego typu i wyszukiwaną wartość i zwraca indeks poszukiwanego elementu.Jeżeli nie zostanie znaleziony, to - 1.
/*
Stwórz klasę Triple, która będzie przechowywać wartości 3 typów.

Posiada konstruktor bezparametryczny
Posiada konstruktor z 3 parametrami
Posiada gettery (getFirst, getSecond, getThird)
Posiada settery (setFirst, setSecond, setThird)
*/