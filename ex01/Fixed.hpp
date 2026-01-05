#include <iostream>
#ifndef FIXED_H
#define FIXED_H

class Fixed {
	private:
		int raw;
		static const int fp_i;
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed(const int i);
		Fixed(const float f);

		Fixed& operator=(const Fixed& f);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, Fixed const &f);

#endif
