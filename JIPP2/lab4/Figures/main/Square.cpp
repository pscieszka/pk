#include "Square.h"

void Square::print() const
{
	std::cout << "X = " << getX() << std::endl;
	std::cout << "Y = " << getY() << std::endl;
	std::cout << "side = " << side << std::endl;
	std::cout << "Area = " << area() << std::endl;
	std::cout << "Circum = " << circum() << std::endl;
}

double Square::area() const
{
	return side*side;
}

double Square::circum() const
{
	return 4*side;
}
