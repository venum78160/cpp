#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "an Cat has just appeared" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << "an Cat has just appeared" << std::endl;
}

Cat::Cat(const Cat	&copy)
{
	this->type = copy.type;
	std::cout << "an Cat has just appeared" << std::endl;
}

Cat::~Cat()
{
	std::cout << "an Cat just died" << std::endl;
}

Cat &Cat::operator=(const Cat& op)
{
	this->type = op.type;
	std::cout << "an Cat has just appeared" << std::endl;
	return(*this);
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miou Ni**a" << std::endl;
}

std::string Cat::getType() const
{
	return (this->type);
}