#include "../include/easyfind.hpp"

int main(void)
{
	std::vector<int> vec = {10, 20, 30, 40, 50};
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 60);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::deque<int> deque = { 1, 2, 3, 100};
	try
	{
		auto it = easyfind(deque, 3);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
