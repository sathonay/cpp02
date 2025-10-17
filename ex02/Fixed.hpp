#include <iostream>
#ifndef FIXED_H
#define FIXED_H

class Fixed {
	private:
		int raw;
		static const int fp_i = 8;
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed(int i);
		Fixed(float f);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed& operator=(const Fixed& l);

		friend bool operator==(const Fixed& l, const Fixed& r);
		friend bool operator!=(const Fixed& l, const Fixed& r);

		friend bool operator<(const Fixed& l, const Fixed& r);
		friend bool operator>(const Fixed& l, const Fixed& r);

		friend bool operator<=(const Fixed& l, const Fixed& r);
		friend bool operator>=(const Fixed& l, const Fixed& r);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		static Fixed&	min(const Fixed& l, const Fixed& r);
		static Fixed&	max(const Fixed& l, const Fixed& r);
};

std::ostream& operator<<(std::ostream &os, Fixed const &f);

#endif
