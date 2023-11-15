#pragma once
#include <iostream>
using namespace std;
class Complex
{
	double x;
	double y;
public:
    Complex() :
        x(0), y(0) {}

    Complex(double x, double y) :
        x(x), y(y) {}
    bool operator==(const Complex& rhs);
    bool operator!=(const Complex& rhs);

    Complex operator+(const Complex& rhs);
    Complex& operator+=(const Complex& rhs);


    friend ostream& operator<<(ostream& lhs, const Complex& rhs);
    friend istream& operator>>(istream& lhs, Complex& rhs);

};

