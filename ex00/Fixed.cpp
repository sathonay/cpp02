#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}

Fixed::Fixed(const int i)
{
	this->raw = 0;
	this->raw |= i << 8;
}

Fixed::Fixed(const float f) : Fixed((int) f)
{
	f -= (int) f;
	int pow = 2;
	for (int i = 0; i < 8; i++)
	{
		if (i != 0)
			pow *= 2;
		float frac = 1 / pow;
		if (frac < f)
		{
			f -= frac;
			this->raw |= 1 << 7 - i;
		}
	}
}

Fixed::Fixed(Fixed& f)
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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt()
{
	return this->raw >> 8;
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
