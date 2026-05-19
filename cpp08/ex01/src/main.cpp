#include "../include/Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	Span sp1(sp);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "--------Copy Constructor Test--------" << std::endl;
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
	std::cout << "--------Copy Assignment Test--------" << std::endl;
	Span sp2(2);
	sp2 = sp1;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "--------Add Multiple Numbers Test--------" << std::endl;
		std::vector<int> nbrs = {50, 100, 2, 0};
		Span sp3(4);
		sp3.addNumbers(nbrs.begin(), nbrs.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "--------Add Too Many Numbers Test--------" << std::endl;
		std::vector<int> nbrs = {0, 5, 2, 100};
		Span sp3(3);
		sp3.addNumbers(nbrs.begin(), nbrs.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "--------Add Too Many Numbers in Multiple Stages Test--------" << std::endl;
		std::vector<int> nbrs = {0, 5, 2, 100};
		Span sp3(4);
		sp3.addNumbers(nbrs.begin(), nbrs.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
		std::vector<int> nbrs1 = {1, 500};
		sp3.addNumbers(nbrs1.begin(), nbrs1.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "--------Add Number Fails Test--------" << std::endl;
		Span sp4 = Span(0);
		sp4.addNumber(6);
		std::cout << sp4.shortestSpan() << std::endl;
		std::cout << sp4.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "--------No Span Test--------" << std::endl; //this should trigger with size 0  or 1 and both with shortest and longest
		Span sp5 = Span(1);
		sp5.addNumber(6);
		std::cout << sp5.shortestSpan() << std::endl;
		std::cout << sp5.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "--------10 000 Numbers test--------" << std::endl;
		std::vector<int> bigVector;
		std::srand(time(nullptr));
		for (int i = 0; i < 10000; ++i)
			bigVector.push_back(rand());
		Span sp6(10000);
		sp6.addNumbers(bigVector.begin(), bigVector.end());
		std::cout << sp6.shortestSpan() << std::endl;
		std::cout << sp6.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "--------Different Container Test--------" << std::endl;
		std::deque<int> deque = { 1, 2, 3, 100};
		Span sp7(4);
		sp7.addNumbers(deque.begin(), deque.end());
		std::cout << sp7.shortestSpan() << std::endl;
		std::cout << sp7.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
