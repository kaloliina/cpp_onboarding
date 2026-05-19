#include <iostream>
#include <exception>
#include <vector>
#include <deque>
#include <algorithm>

template <typename T>
auto easyfind(T& container, int ToFind)
{
	auto it = std::find(container.begin(), container.end(), ToFind);
	if (it == container.end())
		throw std::runtime_error("No occurrence was found.");
	return it;
}
