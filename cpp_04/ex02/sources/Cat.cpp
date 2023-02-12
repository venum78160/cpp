#include "../includes/Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	_brain = new Brain();
	std::cout << "an Cat has just appeared" << std::endl;
}

Cat::Cat(std::string type)
{
	this->type = type;
	_brain = new Brain();
	std::cout << "an Cat has just appeared" << std::endl;
}

Cat::Cat(const Cat	&copy)
{
	this->type = copy.type;
	_brain = new Brain();
	*this->_brain = *copy._brain;
	std::cout << "an Cat has just appeared" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "an Cat just died" << std::endl;
}

Cat &Cat::operator=(const Cat& op)
{
	this->type = op.type;
	_brain = new Brain();
	*this->_brain = *op._brain;
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