#pragma once
#include <iostream>
class Figure
{
protected:
	double* tab;
public:
	Figure(double x, double y) {
		tab = new double[2];
		tab[0] = x;
		tab[1] = y;

	}
	virtual void print() const = 0;
	virtual double area() const = 0;
	virtual double circum() const = 0;

	double getX() const { return tab[0]; }
	double getY() const { return tab[1]; }

	void setX(double x) { tab[0] = x; }
	void setY(double y) { tab[1] = y; }

	virtual ~Figure() {
		delete[] tab;
		std::cout << "Figure destructor called." << std::endl;
	}
};

