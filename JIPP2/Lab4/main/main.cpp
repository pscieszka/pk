// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

#include "Point.h"

int main()
{
    Point p1(1.0, 1.0);
    Point p2(2.0, 1.0);
    std::cout << distance(p1, p2);
    std::cout << p1;

}
