/*
    Write a program to calculate the (Euclidean) distance between two points p 1 {x 1 , y 1 } and p 2 {x 2 , y 2 }. You should write a
    class to represent such points and a method in it which calculates the distance from the point to another point.
*/

#include <iostream>
#include <math.h>

using namespace std;

class Point2D {
    int x;
    int y;
public:
    Point2D(int x, int y) :
        x(x),
        y(y)
    {}

    double distanceToPoint(Point2D p) {
        double deltaX = this->x - p.x;
        double deltaY = this->y - p.y;
        return sqrt(deltaX * deltaX + deltaY * deltaY);
    }
};

int main()
{
    int x, y;
    cin >> x >> y;
    Point2D p1(x, y);
    cin >> x >> y;
    Point2D p2 (x, y);
    cout << p1.distanceToPoint(p2) << endl;
    return 0;
}
