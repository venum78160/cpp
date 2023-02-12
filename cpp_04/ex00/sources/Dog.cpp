#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "an Dog has just appeared" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	std::cout << "an Dog has just appeared" << std::endl;
}

Dog::Dog(const Dog	&copy)
{
	this->type = copy.type;
	std::cout << "an Dog has just appeared" << std::endl;
}

Dog::~Dog()
{
	std::cout << "an Dog just died" << std::endl;
}

Dog &Dog::operator=(const Dog& op)
{
	this->type = op.type;
	std::cout << "an Dog has just appeared" << std::endl;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof Patapouf" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}