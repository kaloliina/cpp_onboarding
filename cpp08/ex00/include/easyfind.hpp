#include <iostream>
#include <exception>
#include <vector>

template <typename T>
auto easyfind(T container, int ToFind)
{
	for (auto it = container.begin(); it != container.end(); ++it)
	{
		if (ToFind == *it)
			return *it;		
	}
	throw std::runtime_error("No occurrence was found.");
}
