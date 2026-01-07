#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {

	Point points[3] = {
		Point(0.0f, 0.0f),
		Point(1.0f, 0.0f),
		Point(0.0f, 1.0f),
	};

	std::cout << bsp(points[0], points[1], points[2], Point(0.25f, 0.25f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.5f, 0.5f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.51f, 0.51f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.502f, 0.502f)) << std::endl;
	std::cout << bsp(points[0], points[1], points[2], Point(0.5019f, 0.5019f)) << std::endl;
}
