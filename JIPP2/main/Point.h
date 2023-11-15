#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Point {
    double x;
    double y;

public:
    Point() :
        x(0), y(0) {}

    Point(double x, double y) :
        x(x), y(y) {}

    void print() {
        cout << x << " " << y << endl;
    }
    bool operator==(const Point& rhs);
    bool operator!=(const Point& rhs);

    friend ostream& operator<<(ostream& lhs, const Point& rhs);
    friend istream& operator>>(istream& lhs, Point& rhs);
    friend double distance(const Point& lhs, const Point& rhs);
};


