#pragma once
class Matrix
{
	double* tab;
	const int col;
	const int row;
public:
	Matrix(int col, int row);
	Matrix(Matrix&);
};

