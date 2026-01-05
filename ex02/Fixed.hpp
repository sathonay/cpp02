#include <iostream>
#ifndef FIXED_H
#define FIXED_H

#define PRINT 0

class Fixed {
	private:
		int raw;
		static const int fp_i;
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed(const int i);
		Fixed(const float f);
		
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed& operator=(const Fixed& l);

		Fixed operator+(const Fixed& o);
		Fixed operator-(const Fixed& o);
		Fixed operator*(const Fixed& o);
		Fixed operator/(const Fixed& o);

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		bool operator==(const Fixed& o) const;
		bool operator!=(const Fixed& o) const;
		bool operator<(const Fixed& o) const;
		bool operator>(const Fixed& o) const;
		bool operator<=(const Fixed& o) const;
		bool operator>=(const Fixed& o) const;

		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		static Fixed&	min(Fixed& l, Fixed& r);
		static Fixed&	max(Fixed& l, Fixed& r);
		static const Fixed&	min(const Fixed& l, const Fixed& r);
		static const Fixed&	max(const Fixed& l, const Fixed& r);
};

std::ostream& operator<<(std::ostream &os, Fixed const &f);

#endif
