#include "Complex.h"

bool Complex::operator==(const Complex& rhs)
{
    return x==rhs.x && y==rhs.y;
}

bool Complex::operator!=(const Complex& rhs)
{
    return x!=rhs.x && y!=rhs.y;
}

Complex Complex::operator+(const Complex& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Complex& Complex::operator+=(const Complex& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

ostream& operator<<(ostream& lhs, const Complex& rhs)
{
    return lhs << rhs.x << "+" << "(" << rhs.y << "i)";
}

istream& operator>>(istream& lhs, Complex& rhs)
{
    return lhs >> rhs.x >> rhs.y;
}
