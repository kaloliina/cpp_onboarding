#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
#include <deque>

class Span
{
	private:
	std::vector<int> vector;
	size_t size;

	public:
	Span() = delete;
	Span(unsigned int N);
	Span(const Span& copy) = default;
	Span& operator=(const Span& src) = default; 
	~Span() = default;

	void	addNumber(int NumberToAdd);
	int		shortestSpan();
	int		longestSpan();

	template <typename It>
	void addNumbers(It begin, It end)
	{
		int rangesize = std::distance(begin, end);
		if (size < rangesize + vector.size())
			throw std::runtime_error("Cannot store more integers");
		vector.insert(vector.end(), begin, end);
	};
};
