#include <iostream>
#include <math.h>
#include "Fixed.hpp"

const int Fixed::fp_i = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
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
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int i)
{
	this->raw = i << this->fp_i;
}

Fixed::Fixed(float f)
{
	this->raw = roundf(f * (1 << this->fp_i));
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw;
}

void	Fixed::setRawBits( int const raw )
{
	this->raw = raw;
}
