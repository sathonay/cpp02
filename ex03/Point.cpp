#include "Point.hpp"

Point::Point(float x, float y)
{
	this->x = Fixed(x);
	this->y = Fixed(y);
}


Point::Point(Fixed x, Fixed y)
{
	this->x = x;
	this->y = y;
}

Point::Point() : x(Fixed(0.0f)), y(Fixed(0.0f)) {}

Point::Point(const Point &p) {
	this->x = p.x;
	this->y = p.y;
}

Point::~Point() {}

Point& Point::operator=(const Point& p)
{
	this->x = p.getX();
	this->y = p.getY();
	return (*this);
}

Point Point::operator-(const Point& b) const
{
	Point p(
		b.getX() - this->getX(),
		b.getY() - this->getY()
	);
	return p;
}

Fixed Point::getX() const {
	return this->x;
}
Fixed Point::getY() const {
	return this->y;
}
