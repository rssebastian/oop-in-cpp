#include "Point.h"
#include "Sphere.h"
#include <iostream>
using namespace std;

int main()
{
    Point p1;
    cout << "Default p1 X: " << p1.getX() << endl;
    cout << "Default p1 Y: " << p1.getY() << endl;
    cout << "Default p1 Z: " << p1.getZ() << endl;

    cout << "Testing changing p1 values..." << endl;
    p1.setX(4);
    p1.setY(4);
    p1.setZ(4);
    cout << "Default p1 X: " << p1.getX() << endl;
    cout << "Default p1 Y: " << p1.getY() << endl;
    cout << "Default p1 Z: " << p1.getZ() << endl;

    Point p2 = Point(1, 2, 3);
    cout << "Custom p2 X: " << p2.getX() << endl;
    cout << "Custom p2 Y: " << p2.getY() << endl;
    cout << "Custom p2 Z: " << p2.getZ() << endl;

    Sphere s1 = Sphere(5);
    cout << "Sphere s1 Center X: " << s1.getCenter().getX() << endl;
    cout << "Sphere s1 Center Y: " << s1.getCenter().getY() << endl;
    cout << "Sphere s1 Center Z: " << s1.getCenter().getZ() << endl;
    cout << "Sphere s1 Radius: " << s1.getRadius() << endl;
    cout << "Sphere s1 Volume: " << s1.getVolume() << endl;
    cout << "Sphere s1 Surface Area: " << s1.getSurfaceArea() << endl;

    Sphere s2 = Sphere(Point(5, 6, 7), 8);
    cout << "Sphere s2 Center X: " << s2.getCenter().getX() << endl;
    cout << "Sphere s2 Center Y: " << s2.getCenter().getY() << endl;
    cout << "Sphere s2 Center Z: " << s2.getCenter().getZ() << endl;
    cout << "Sphere s2 Radius: " << s2.getRadius() << endl;
    cout << "Sphere s2 Volume: " << s2.getVolume() << endl;
    cout << "Sphere s2 Surface Area: " << s2.getSurfaceArea() << endl;

    return 0;
}

// TEST CASE OUTPUT
// Default p1 X: 0
// Default p1 Y: 0
// Default p1 Z: 0
// Testing changing p1 values...
// Default p1 X: 4
// Default p1 Y: 4
// Default p1 Z: 4
// Custom p2 X: 1
// Custom p2 Y: 2
// Custom p2 Z: 3
// Sphere s1 Center X: 0
// Sphere s1 Center Y: 0
// Sphere s1 Center Z: 0
// Sphere s1 Radius: 5
// Sphere s1 Volume: 523.599
// Sphere s1 Surface Area: 314.159
// Sphere s2 Center X: 5
// Sphere s2 Center Y: 6
// Sphere s2 Center Z: 7
// Sphere s2 Radius: 8
// Sphere s2 Volume: 2144.66
// Sphere s2 Surface Area: 804.248