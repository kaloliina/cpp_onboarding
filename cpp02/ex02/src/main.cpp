#include "../include/Fixed.hpp"

int main( void ) {
Fixed a(Fixed(100) + Fixed(2));
Fixed b(Fixed(10.1f) - Fixed(2));
Fixed c(Fixed(42.42f) / Fixed(2));
Fixed d(Fixed(-5.0f) * Fixed(2));
Fixed e(-10);
Fixed f(0);

std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "e is " << e << std::endl;
std::cout << "f is " << f << std::endl;

if (a > b)
	std::cout << a << " > " << b << " is true" << std::endl;
else
	std::cout << a << " > " << b << " is false" << std::endl;
if (a < b)
	std::cout << a << " < " << b << " is true" << std::endl;
else
	std::cout << a << " < " << b << " is false" << std::endl;
if (a >= b)
	std::cout << a << " >= " << b << " is true" << std::endl;
else
	std::cout << a << " >= " << b << " is false" << std::endl;
if (d <= e)
	std::cout << d << " <= " << e << " is true" << std::endl;
else
	std::cout << d << " <= " << e << " is false" << std::endl;
if (d == e)
	std::cout << d << " == " << e << " is true" << std::endl;
else
	std::cout << d << " == " << e << " is false" << std::endl;
if (d != e)
	std::cout << d << " != " << e << " is true" << std::endl;
else
	std::cout << d << " != " << e << " is false" << std::endl;

std::cout << f << std::endl;
std::cout << ++f << std::endl;
std::cout << f++ << std::endl;
std::cout << f << std::endl;
std::cout << --f << std::endl;
std::cout << f-- << std::endl;
std::cout << f << std::endl;

Fixed f1(42.42f);
Fixed f2(21.21f);

std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
std::cout << "min(f1, f2) = " << Fixed::findMin(f1, f2) << std::endl;
std::cout << "max(f1, f2) = " << Fixed::findMax(f1, f2) << std::endl;

return 0;
}

