#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixed_value;
	static const int fractional = 8;
public:
	Fixed();
	Fixed(const int ints);
	Fixed(const float floats);
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed &src); 
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );	
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
