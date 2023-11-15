#include "Point.h"

ostream& operator<<(ostream& lhs, const Point& rhs)
{
    return lhs << rhs.x << " " << rhs.y;
}

istream& operator>>(istream& lhs,Point& rhs)
{
    lhs >> rhs.x >> rhs.y;
    return lhs;

}

double distance(const Point& lhs, const Point& rhs)
{
    return sqrt(pow(rhs.x - lhs.x, 2) + pow(rhs.y - lhs.y, 2));
}

bool Point::operator==(const Point& rhs)
{
    return x==rhs.x && y==rhs.y;
}

bool Point::operator!=(const Point& rhs)
{
     return x != rhs.x && y != rhs.y;
    
}
