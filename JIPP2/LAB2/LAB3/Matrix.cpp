#include "Matrix.h"

Matrix::Matrix(int col, int row) :  col(col), row(row)
{
	matrix = new double*[row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[col];
	}
}


Matrix::~Matrix()
{
	for (int i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}


Matrix::Matrix(const Matrix& matrixCopy) : col(matrixCopy.col), row(matrixCopy.row), failed(matrixCopy.failed)
{
	matrix = new double* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[col];
		for (int j = 0; j < col; j++) {
			matrix[i][j] = matrixCopy.matrix[i][j];
		}
	}
}

double Matrix::getValue(int col, int row)
{
	if (col<0 || row<0 || col>this->col || row>this->row) {
		failed = true;
		return 0;
	}
	else {
		return matrix[row][col];
	}
}

bool Matrix::fail()
{
	return failed;
}

void Matrix::resetFail()
{
	failed = false;
}

void Matrix::rand()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> distribution(0.0, 100.0);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = distribution(gen);
		}
	}
}

void Matrix::insertValue(int col, int row, double newVal)
{
	if (col<0 || row<0 || col>this->col || row>this->row) {
		failed = true;
	}
	else {
		matrix[row][col] = newVal;
	}
	

}
