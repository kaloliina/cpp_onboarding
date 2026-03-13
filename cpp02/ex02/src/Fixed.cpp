#include "../include/Fixed.hpp"

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
Fixed::Fixed() : fixed_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
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

//Comparison Operators
bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other.getRawBits());
}

//Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other)
{
	this->fixed_value = this->fixed_value + other.fixed_value;
	return (*this);
}
Fixed Fixed::operator-(const Fixed &other)
{
	this->fixed_value = this->fixed_value - other.fixed_value;
	return (*this);
}

/* Since both numbers are already saved as fixed points, which means scaled by 256,
after multiplying we need to divide it with 256 so it's only scaled "once"*/
Fixed Fixed::operator*(const Fixed &other)
{
	long long new_fixed;
	new_fixed = this->fixed_value * other.fixed_value;
	new_fixed = new_fixed >> fractional;
	this->fixed_value = new_fixed;
	return (*this);
}

/* Multiply the number to be divided with 256 so we don't lose the fractional bits.*/
Fixed Fixed::operator/(const Fixed &other)
{
	long long new_fixed;
	new_fixed = this->fixed_value * 256;
	this->fixed_value = new_fixed / other.fixed_value;
	return (*this);
}

//Increment/Decrement Operators
/*Post increments make a copy of the object, increment the original object
and return the copy that is then used in the expression.*/
Fixed& Fixed::operator++()
{
	this->fixed_value = this->fixed_value + 1;
	return (*this);
}

Fixed& Fixed::operator--() 
{
	this->fixed_value = this->fixed_value - 1;
	return (*this);
}

Fixed Fixed::operator++(int) 
{
	Fixed temp(*this);

	this->fixed_value = this->fixed_value + 1;
	return (temp);
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	this->fixed_value = this->fixed_value - 1;
	return (temp);
}

Fixed& Fixed::findMin(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	else
		return (nbr2);
}
const Fixed& Fixed::findConstMin(const Fixed &nbr1, const Fixed &nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	else
		return (nbr2);
}

Fixed& Fixed::findMax(Fixed &nbr1, Fixed &nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	else
		return (nbr2);
}
const Fixed& Fixed::findConstMax(const Fixed &nbr1, const Fixed &nbr2)
{
	if (nbr1 > nbr2)
		return (nbr1);
	else
		return (nbr2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
