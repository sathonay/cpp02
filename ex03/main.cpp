#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

//https://stackoverflow.com/a/2049712
//https://stackoverflow.com/a/34093754
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed dX = point.getX() - c.getX();
    Fixed dY = point.getY() - c.getY();
    Fixed dX21 = c.getX() - b.getX();
    Fixed dY12 = b.getY() - c.getY();
    Fixed D = dY12 * (a.getX() - c.getX()) + dX21*(a.getY() - c.getY());
    Fixed s = dY12*dX + dX21*dY;
    Fixed t = (c.getY() - a.getY())*dX + (a.getX() - c.getX())*dY;
    if (D<0) return s<=0 && t<=0 && s+t>=D;
    return s>=0 && t>=0 && s+t<=D;
}

int main() {

	Point points[3] = {
		Point(0.0f, 0.0f),
		Point(0.0f, 1.0f),
		Point(1.0f, 0.0f),
	};

	std::cout << bsp(points[0], points[1], points[2], Point(0.5f, 0.5f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.51f, 0.51f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.502f, 0.502f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.5019f, 0.5019f)) << std::endl;
}