#include <iostream>
#include "Matrix.h"

int main()
{
    std::cout << "Hello World!\n";
    Matrix matrix(5, 5);
    matrix.rand();
    std::cout<<matrix.getValue(1, 1)<<std::endl;
    matrix.insertValue(1, 1, 19);
    std::cout << matrix.getValue(1, 1) << std::endl;
    matrix.insertValue(444, 444, 233);
    if (matrix.fail()) {
        std::cout << "failed"<<std::endl;
    }
    Matrix matrix2(matrix);
    std::cout << matrix2.getValue(1, 1) << std::endl;


}

