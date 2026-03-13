#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "This is a default idea...";
	}
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain Copy Constructor called!" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = copy.ideas[i];
	}
}

Brain& Brain::operator=(const Brain &src)
{
	std::cout << "Brain Copy Assignment called!" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = src.ideas[i];
		}		
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called!" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return (ideas[index]);
}
