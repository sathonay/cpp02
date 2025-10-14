#ifndef FIXED_H
#define FIXED_H

class Fixed {
	private:
		int raw;
		static const int fp_i = 8;
	public:
		Fixed();
		Fixed(Fixed& f);
		Fixed& operator=(const Fixed& f);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
