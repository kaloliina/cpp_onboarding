#include "../include/Span.hpp"

Span::Span(unsigned int N)
{
	size = N;
}

void	Span::addNumber(int NumberToAdd)
{
	if ((int)vector.size() == size)
		throw std::runtime_error("Cannot store more integers");
	vector.push_back(NumberToAdd);
}

int	Span::shortestSpan()
{
	if (vector.size() == 0 || vector.size() == 1)
		throw std::runtime_error("No span cannot be found if vector size is 0 or 1");
	std::sort(vector.begin(), vector.end());
	int shortestSpan = -1;
	for (auto it = vector.begin(); it + 1 != vector.end(); ++it)
	{
		if (shortestSpan == -1 || (it != vector.end() && (*(it + 1) - *it < shortestSpan )))
		{
			shortestSpan = *(it + 1) - *it;
		}
	}
	return shortestSpan;
}

int	Span::longestSpan()
{
	if (vector.size() == 0 || vector.size() == 1)
		throw std::runtime_error("No span cannot be found if vector size is 0 or 1");
	std::sort(vector.begin(), vector.end());
	return (vector[vector.size() - 1] - vector[0]); //this one is not very elegant
}
