// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "Figure.h"
#include "Circle.h"
#include "Square.h"
int main()
{
    Figure* fig = new Circle(2.3, 3.4, 2.3);
    fig->print();
    delete fig;
    fig = new Square(1.0, 1.0, 2.0);
    fig->print();


    delete fig;
}


