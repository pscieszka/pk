#pragma once
#include "Figure.h"
class Square : public Figure
{

private:
	double side;
public:

	Square(double x, double y, double side) : Figure(x, y), side(side) {};

	void print() const override;
	double area() const override;
	double circum() const override;

	~Square() override {
		std::cout << "Square destructor called." << std::endl;
	}
};

