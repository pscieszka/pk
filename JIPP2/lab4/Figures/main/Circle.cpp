#include "Circle.h"

double Circle::area() const
{
	return  3.14159 * radius * radius;;
}
double Circle::circum() const
{
	return 2 * 3.14159 * radius;
}
void Circle::print() const {

	std::cout << "X = " << getX() << std::endl;
	std::cout << "Y = " << getY() << std::endl;
	std::cout << "Radius = " << radius << std::endl;
	std::cout << "Area = " << area() << std::endl;
	std::cout << "Circum = " << circum() << std::endl;
}


