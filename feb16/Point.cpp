#include "Point.h"

using namespace std;

Point::Point()
{
    xCoord = 0;
    yCoord = 0;
    zCoord = 0;
}

Point::Point(double x, double y, double z)
{

    xCoord = x;
    yCoord = y;
    zCoord = z;
}

void Point::setX(double x)
{
    xCoord = x;
}

void Point::setY(double y)
{
    yCoord = y;
}

void Point::setZ(double z)
{
    zCoord = z;
}