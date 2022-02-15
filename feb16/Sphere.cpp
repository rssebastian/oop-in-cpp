#include "Sphere.h"
#include "Point.h"
#include <math.h>

using namespace std;

Sphere::Sphere(Point center, double radius)
{
    this->center = center;
    this->radius = radius;
}

Sphere::Sphere(double radius)
{
    center = Point(0, 0, 0);
    this->radius = radius;
}

double Sphere::getVolume()
{
    return (4 * M_PI * pow(radius, 3) / 3);
};

double Sphere::getSurfaceArea()
{
    return (4 * M_PI * pow(radius, 2));
};