#include "../includes/Brain.hpp"


Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Idea " + std::to_string(i);
	std::cout << "A new brain has been created" << std::endl;
}

Brain::Brain(const Brain	&copy)
{
	std::cout << "A copy of brain has been made" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "An Brain just died" << std::endl;
}

Brain &Brain::operator=(const Brain& op)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = op.ideas[i];
	std::cout << "The brain has been copied" << std::endl;
	return(*this);
}