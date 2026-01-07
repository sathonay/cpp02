#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "Fixed.hpp"

class Point {
	private:
		Fixed x, y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point &p);
		~Point();
		Point& operator=(const Point &p);

		Point(Fixed x, Fixed y);
		Point operator-(const Point& p) const;
		Fixed getX() const;
		Fixed getY() const;
};

#endif
