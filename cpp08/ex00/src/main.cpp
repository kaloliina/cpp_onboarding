#include "../include/easyfind.hpp"

int main(void)
{
	std::vector<int> vec = {10, 20, 30, 40, 50};
	try
	{
		auto it = easyfind(vec, 60);
		std::cout << it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
