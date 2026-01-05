#include <iostream>
#include <math.h>
#include "Fixed.hpp"

const int Fixed::fp_i = 8;

Fixed::Fixed()
{
	if (PRINT)
		std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(const Fixed& f)
{
	if (PRINT)
		std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	if (PRINT)
		std::cout << "Copy assignment operator called" << std::endl;
	this->raw = f.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	if (PRINT)
		std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	this->raw = i << this->fp_i;
	if (PRINT)
		std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
{
	this->raw = roundf(f * (1 << this->fp_i));
	if (PRINT)
		std::cout << "Float constructor called" << std::endl;
}

int Fixed::toInt() const 
{
	return (this->raw >> this->fp_i);
}

float Fixed::toFloat() const
{
	return ((float)this->raw / (1 << this->fp_i));
}

int		Fixed::getRawBits( void ) const
{
	if (PRINT)
		std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits( int const raw )
{
	this->raw = raw;
}

Fixed Fixed::operator+(const Fixed& o) const
{
	Fixed ret;
	ret.setRawBits(this->getRawBits() + o.getRawBits());
	return ret;
}

Fixed Fixed::operator-(const Fixed& o) const
{
	Fixed ret;
	ret.setRawBits(this->getRawBits() - o.getRawBits());
	return ret;
}

Fixed Fixed::operator*(const Fixed& o) const
{
	Fixed ret;
	ret.setRawBits((this->getRawBits() * o.getRawBits()) >> fp_i);
	return ret;
}

Fixed Fixed::operator/(const Fixed& o) const
{
	return Fixed(this->getRawBits() / o.getRawBits());
}

Fixed& Fixed::operator++()
{
	this->raw++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->raw--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed prev = *this;
	this->raw++;
	return prev;
}

Fixed Fixed::operator--(int)
{
	Fixed prev = *this;
	this->raw--;
	return prev;
}

bool Fixed::operator==(const Fixed& o) const
{
	return (this->getRawBits() == o.getRawBits());
}

bool Fixed::operator!=(const Fixed& r) const
{
	return (!(*this == r));
}

bool Fixed::operator<(const Fixed& r) const
{
	return (this->getRawBits() < r.getRawBits());
}

bool Fixed::operator>(const Fixed& r) const
{
	return (r < *this);
}

bool Fixed::operator<=(const Fixed& r) const
{
	return !(*this > r);
}

bool Fixed::operator>=(const Fixed& r) const
{
	return !(*this < r);
}

Fixed&	Fixed::min(Fixed& l, Fixed& r)
{
	return (l < r ? l : r);
}

Fixed&	Fixed::max(Fixed& l,  Fixed&r)
{
	return (l > r ? l : r);
}

const Fixed&	Fixed::min(const Fixed& l, const Fixed& r)
{
	return (l < r ? l : r);
}

const Fixed&	Fixed::max(const Fixed& l, const  Fixed&r)
{
	return (l > r ? l : r);
}

