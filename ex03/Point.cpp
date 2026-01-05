#include "Point.hpp"

Point::Point(float x, float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point() : x(Fixed(0.0f)), y(Fixed(0.0f)) {}

Point::Point(const Point &p) {
	this->x = p.x;
	this->y = p.y;
}

Point::~Point() {}

Fixed Point::getX() const {
	return this->x;
}
Fixed Point::getY() const {
	return this->y;
}