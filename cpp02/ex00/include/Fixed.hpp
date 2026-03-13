#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

/*Static in this case means:
- Member belongs to the class itself, not to the objects.
- Only one copy of it shared by all objects.*/
class Fixed {
private:
	int fixed_value;
	static const int fractional = 8;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed &operator=(const Fixed &src); 
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
