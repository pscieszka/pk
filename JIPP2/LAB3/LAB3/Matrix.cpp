#include "Matrix.h"

Matrix::Matrix(int col, int row) :  col(col), row(row)
{
	tab = new double[row*col];
}
