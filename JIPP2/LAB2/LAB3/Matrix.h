#pragma once
#include <random>

class Matrix
{
	double** matrix;
	int col;
	int row;
	bool failed=false;
public:
	Matrix(int col, int row);
	Matrix(const Matrix& matrixCopy);
	~Matrix();

	void insertValue(int col, int row, double newVal);
	double getValue(int col, int row);
	bool fail();
	void resetFail();
	void rand();
};

