// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Point {
    string name;
    int dim;
    vector<int> nums;
public:
    Point(string name, int dim) : name(name), dim(dim),nums(dim,0) {
        
    }
    void setData(vector<int> data) {

        for (int i = 0; i < min(nums.size(),data.size()); i++) {
            nums[i] = data[i];
        }
    }
    void savePoint(ofstream& file) {
        if (file.is_open()) {
            int sizeName = name.size();
            file.write(reinterpret_cast<char*>(&sizeName), sizeof(int));
            file.write(name.c_str(), sizeName);
            file.write(reinterpret_cast<char*>(&dim), sizeof(dim));
            for (int i = 0; i < dim; i++) {
                file.write(reinterpret_cast<char*>(&nums[i]), sizeof(nums[i]));
            }
        }
    }
    void readPoint(ifstream& file) {
        if (file.is_open()) {
            int sizeName;
            file.read(reinterpret_cast<char*>(&sizeName), sizeof(int));
            string data(sizeName, ' ');
            file.read(&data[0], sizeName);

            int dim;
            this->name = data;
            file.read(reinterpret_cast<char*>(&dim), sizeof(int));
            this->dim = dim;

            nums.resize(dim);
            for (int i = 0; i < dim; i++) {
                file.read(reinterpret_cast<char*>(&nums[i]), sizeof(int));
            }


        }
    }
    void printData() const {
        cout << "Name: " << name << endl;
        cout << "Dimensions: " << dim << endl;
        cout << "Coordinates: ";
        for (int i = 0; i < dim; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }


};

int main()
{
    Point p("cos", 5);
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8 };
    p.setData(vec);
    p.printData();

    // Zapis do pliku
    ofstream file("data", ios::binary);
    if (file.is_open()) {
        p.savePoint(file);
        file.close(); // Zamkniêcie pliku po zapisie
    }


    // Odczyt z pliku
    ifstream readFile("data", ios::binary);
    if (readFile.is_open()) {
        Point loadedPoint("LoadedPoint", 100);
        loadedPoint.readPoint(readFile);
        readFile.close(); // Zamkniêcie pliku po odczycie
        loadedPoint.printData();
    }








    /*
   
    ifstream file("dataQuotes.csv");

    ofstream trams("trams.csv");
    ofstream buses("buses.csv");

    if (file.good()) {
        string s;
        while (getline(file,s)) {

            if (s.size()>4  && !isdigit(s[3]) ) {

                if (trams.good()) {
                    trams << s << endl;
                }

                else {
                    cout << "trams not good"<<endl;
                }

            }

            else if (s.size() > 4 && isdigit(s[3]) ) {

                if (buses.good()) {
                    buses << s << endl;
                }

                else {
                    cout << "buses not good" << endl;

                }
            }
        }
    }

    else {
        cout << "bad" << endl;

    }
    file.close();
    trams.close();
    buses.close();
     */




}

/*
* Stwórz program, który bêdzie wczytywa³ plik csv, w którym s¹ zapisane kolejno:
* numer linii
przystanek pocz¹tkowy
przystanek koñcowy
operator
Nastêpnie zapisywa³ w osobnym pliku linie tramwajowe, a w osobnym autobusowe (linie tramwajowe maj¹ 1 lub 2 cyfry, a autobusowe 3), 
w takim samym uk³adzie (takie same kolumny, taka sama ich kolejnoœæ).


Stwórz klasê przechowuj¹c¹ punkty. Podczas tworzenia punktu u¿ytkownik deklaruje, 
w ilu wymiarowej przestrzeni bêd¹ one sytuowane. Dodatkowo musz¹ one przechowywaæ jego nazwê.
Klasa powinna posiadaæ metodê s³u¿¹c¹ do zapisu tych danych do binarnego strumienia plikowego
przekazanego przez parametr oraz kolejn¹ metodê do jego odczytywania.
*/