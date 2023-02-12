#include "../includes/Animal.hpp"


Animal::Animal()
{
	this->type = "Unknow animal";
	std::cout << "an animal has just appeared" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "an animal has just appeared" << std::endl;
}

Animal::Animal(const Animal	&copy)
{
	this->type = copy.type;
	std::cout << "an animal has just appeared" << std::endl;
}

Animal::~Animal()
{
	std::cout << "an animal just died" << std::endl;
}

Animal &Animal::operator=(const Animal& op)
{
	this->type = op.type;
	std::cout << "an animal has just appeared" << std::endl;
	return(*this);
}

void Animal::makeSound() const
{
	std::cout << "***Animal sound***" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}