#include "../include/Array.hpp"

class Test
{
	public:
	int x;

	Test() : x(8) {}
};

int main( void )
{
	try
	{
		std::cout << "--------Empty array test--------" << std::endl;
		Array<int> emptyArray(0);
		Array<int> emptyArray1;
		std::cout << "Empty array size: " << emptyArray.size() << " and empty array1 size: " << emptyArray1.size() << std::endl;

		std::cout << "--------Parameterized constructor test--------" << std::endl;
		Array<std::string> arr(4);
		arr[0] = "a";
		arr[1] = "b";
		arr[2] = "c";
		arr[3] = "d";
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << "arr[" << i << "]: " << arr[i] << std::endl;		
		}
		std::cout << std::endl;

		std::cout << "--------Copy constructor test--------" << std::endl;
		Array<std::string> arr1(arr);

		std::cout << "Original arr[0]: " << arr[0] << std::endl;
		std::cout << "Copied arr1[0]: " << arr1[0] << std::endl;
		arr1[0] = "HELLO";
		std::cout << "Original arr[0]: " << arr[0] << std::endl;
		std::cout << "Copied arr1[0]: " << arr1[0] << std::endl;
		std::cout << std::endl;
		std::cout << "--------Copy assignment with same size test--------" << std::endl;
		Array<std::string> arr2(4);
		arr2 = arr;
		for (int i = 0; i < arr.size(); i++)
		{
			std::cout << "Original arr[" << i << "]: " << arr[i] << std::endl;
			std::cout << "Assigned arr2[" << i << "]: " << arr2[i] << std::endl;	
		}
		arr2[1] = "They see me modifying, they hatin'";
		std::cout << "Original arr[1]: " << arr[1] << std::endl;
		std::cout << "Assigned arr2[1]: " << arr2[1] << std::endl;
		std::cout << std::endl;

		std::cout << "--------Copy assignment with different size test--------" << std::endl;
		Array<std::string> arr3(2);
		arr3[0] = "oldie";
		arr3[1] = " but goldie";
		for (int i = 0; i < arr3.size(); i++)
		{
			std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;		
		}
		std::cout << "Size of arr3: " << arr3.size() << std::endl;
		std::cout << "Size of arr: " << arr.size() << std::endl;
		arr3 = arr;
		for (int i = 0; i < arr3.size(); i++)
		{
			std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;		
		}
		std::cout << "Size of arr3: " << arr3.size() << std::endl;
		std::cout << std::endl;
		try
		{
			std::cout << "--------Modifying out of bounds test--------" << std::endl;
			arr[4] = "oops";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		try
		{
			std::cout << "--------Accessing out of bounds test--------" << std::endl;
			std::cout << "Attempting to access something out of bounds..: " << arr[4] << std::endl;;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
		std::cout << "--------Assigning to 0 sized array--------" << std::endl;
		Array<int> zero(0);
		Array<int> other(2);
		other[0] = 10;
		other[1] = 20;
		zero = other;
		std::cout << "Size of zero :" << zero.size() << std::endl;
		std::cout << std::endl;

		std::cout << "--------Array of objects test--------" << std::endl;
		Array<Test> testArray(3);
		std::cout << testArray[0].x << std::endl;
		std::cout << "Size of testArray: " << testArray.size() << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
