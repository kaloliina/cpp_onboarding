#include "../include/iter.hpp"

template <typename T>
void increaseThis(T& y)
{
	std::cout << "Before increase: " << y << std::endl;
	y++;
	std::cout << "After increase: " << y << std::endl;
}

template <typename T>
void printThis(const T& y)
{
	std::cout << "Printing: " << y << std::endl;
}

int main()
{
	//Regular test
	int arr[] = {1, 2, 3};
	::iter(arr, 3, increaseThis<int>);
	std::cout << std::endl;
	::iter(arr, 3, printThis<int>);

	const int arr1[] = {8, 9, 10};
//	::iter(arr1, 3, increaseThis<int>); //This should not even compile because because the function is expecting a non-const array element and this is const.
	std::cout << std::endl;
	::iter(arr1, 3, printThis<int>);

	//Empty array
	int empty[] = {};
	::iter(empty, 0, printThis<int>);

	//Empty array
	int length[] = {1, 2, 3};
	::iter(length, 0, printThis<int>);

	//Null
	int *ptr = nullptr;
	::iter(ptr, 5, printThis<int>);
}