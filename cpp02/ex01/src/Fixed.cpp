#include "../include/Fixed.hpp"

Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int ints)
{
	std::cout << "Int Constructor called" << std::endl;
	fixed_value = ints << fractional;
}

Fixed::Fixed(const float floats)
{
	std::cout << "Float Constructor called" << std::endl;
	fixed_value = roundf(floats * 256);
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->fixed_value = copy.fixed_value;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy Assignment called" << std::endl;
	if (this != &src)
	{
		this->fixed_value = src.fixed_value;	
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Default Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	float f = (float)(fixed_value / 256.0);
	return f;
}

int Fixed::toInt( void ) const 
{
	int i = fixed_value >> fractional;
	return i;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	fixed_value = raw;
}

/*Built-in types like int float are printed by default but since Fixed is created by us,
it doesn't know how to print it! That's why we overload the stream insertion operator.
- std::ostream& os is the output stream (in this case std::cout)
- Return type std::ostream& allows chaining multiple calls.
When the compiler sees <<, it checks if the output stream matches and we are referring to
Fixed object, then it knows to use the overload.*/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}