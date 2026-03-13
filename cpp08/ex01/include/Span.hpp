#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Span
{
	private:
	std::vector<int> vector;
	int size;

	public:
	Span() = delete;
	Span(unsigned int N);
	Span(const Span& copy) = default; //double check these
	Span& operator=(const Span& src) = default; 
	~Span() = default;

	void	addNumber(int NumberToAdd);
	int		shortestSpan();
	int		longestSpan();

	template <typename It>
	void addNumbers(It begin, It end)
	{
		int rangesize = std::distance(begin, end);
		if (size < rangesize + (int)vector.size())
			throw std::runtime_error("Cannot store more integers"); //hmm?
		while (begin != end)
		{
			vector.push_back(*begin);
			++begin;
		}
	};
};
