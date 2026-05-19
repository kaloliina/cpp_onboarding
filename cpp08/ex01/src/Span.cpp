#include "../include/Span.hpp"

Span::Span(unsigned int N)
{
	size = N;
}

void	Span::addNumber(int NumberToAdd)
{
	if (vector.size() == size)
		throw std::runtime_error("Cannot store more integers");
	vector.push_back(NumberToAdd);
}

int	Span::shortestSpan()
{
	if (vector.size() == 0 || vector.size() == 1)
		throw std::runtime_error("No span cannot be found if vector size is 0 or 1");
	std::vector<int> veccopy = vector;
	std::sort(veccopy.begin(), veccopy.end());
	int shortestSpan = -1;
	int currentSpan;
	for (auto it = veccopy.begin(); it + 1 != veccopy.end(); ++it)
	{
		currentSpan = *(it + 1) - *it;
		if (shortestSpan == -1 || currentSpan < shortestSpan )
			shortestSpan = currentSpan;
	}
	return shortestSpan;
}

int	Span::longestSpan()
{
	if (vector.size() == 0 || vector.size() == 1)
		throw std::runtime_error("No span cannot be found if vector size is 0 or 1");
	return *std::max_element(vector.begin(), vector.end()) - *std::min_element(vector.begin(), vector.end());
}
