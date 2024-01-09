

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

class student {
public:
    string imie;
    string nazwisko;

    student(string imie, string nazwisko) : imie(imie), nazwisko(nazwisko) {}
    bool operator==(const student& other) const {
        return (imie == other.imie && nazwisko == other.nazwisko);
    }
};
int main()
{
    vector<int> vec;
    auto start = chrono::system_clock::now();
    for (int i = 0; i < 1000000; i++) {
        vec.push_back(i);
    }
    auto stop = chrono::system_clock::now();
    auto elapsed = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    cout << elapsed << " ms" << endl;


    vector<int> vec2;
    vec2.reserve(1000000);

    start = chrono::system_clock::now();
    for (int i = 0; i < 1000000; i++) {
        vec2.push_back(i);
    }
    stop = chrono::system_clock::now();
    elapsed = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    cout << elapsed << " ms" << endl;
    // 2-3 ms roznicy

    vector<int>vec3 = { 1,4,2,3,1,3,4,5,7,8,9,1,2,3,4,5,6,7,8,90,1,12,3,4 };
    sort(vec3.begin(), vec3.end());
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3[i] << ", ";
    }
    cout << endl;

    sort(vec3.begin(), vec3.end(), [](int a, int b) {
        return a>b;
        });
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3[i] << ", ";
    }
    cout << endl;

    student s1("jan", "kowalski");
    student s2("kuba", "kubowski");
    student s3("jan", "nowak");
    student s4("jan", "kowalski");
    student s5("jakub", "kowalski");
    student s6("grzegorz", "kowal");
    vector<student> vec4 = { s1,s2,s3,s4,s5,s6 };
    string szukaneImie = "jan";
    string szukaneNazwisko = "nowak";
    auto it = find(vec4.begin(), vec4.end(), student(szukaneImie, szukaneNazwisko));

    if (it != vec4.end()) {
        cout << "znaleziono "<<it->imie<<" "<<it->nazwisko << endl;
    }
    else {
        cout << "nie znaleziono " << endl;
    }
    string naz = "kubowski";
    it = find_if(vec4.begin(), vec4.end(), [&naz](const student& s) {
        if (naz == s.nazwisko) {
            return true;
        }
        return false;
        });

    if (it != vec4.end()) {
        cout << "znaleziono " << it->imie << " " << it->nazwisko << endl;
    }
    else {
        cout << "nie znaleziono " << endl;
    }
}

