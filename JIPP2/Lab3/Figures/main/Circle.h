#pragma once
#include "Figure.h"
class Circle : public Figure
{
private:
	double radius;
public:
	Circle(double x, double y, double radius) : Figure(x, y), radius(radius) {};

	void print() const override;
	double area() const override;
	double circum() const override;

	~Circle() override {
		std::cout << "Circle destructor called." << std::endl;
	}
};

