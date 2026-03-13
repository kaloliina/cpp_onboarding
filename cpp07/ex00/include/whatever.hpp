#pragma once
#include <iostream>
/*templates in C++ are powerful tools for creating generic classes or functions.
This allows us to write code that works for any data type without rewriting it for each type.

So templates are not actual functions or classes by themselves, they are more like blueprints!
So when we compile our program and we call to something with a datatype, 
for example creating a class, calling a function etc, the function/class/etc will get compiled
at a compile time.
*/

template <typename T>
void	swap(T& x, T& y)
{
	T z = x;
	x = y;
	y = z;
}
/*If equal, returns the second one*/
template <typename T>
T&	min(T& x, T& y)
{
	if (x < y)
		return x;
	else if (y < x)
		return y;
	else
		return y;
}
/*If equal, returns the second one*/
template <typename T>
T&	max(T& x, T& y)
{
	if (x > y)
		return x;
	else if (y > x)
		return y;
	else
		return y;
}
