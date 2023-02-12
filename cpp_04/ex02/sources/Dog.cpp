#include "../includes/Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	_brain = new Brain();
	std::cout << "an Dog has just appeared" << std::endl;
}

Dog::Dog(std::string type)
{
	this->type = type;
	_brain = new Brain();
	std::cout << "an Dog has just appeared" << std::endl;
}

Dog::Dog(const Dog	&copy)
{
	this->type = copy.type;
	_brain = new Brain();
	*this->_brain = *copy._brain;
	std::cout << "an Dog has just appeared" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "an Dog just died" << std::endl;
}

Dog &Dog::operator=(const Dog& op)
{
	this->type = op.type;
	_brain = new Brain();
	*this->_brain = *op._brain;
	std::cout << "an Dog has just appeared" << std::endl;
	return(*this);
}

void Dog::makeSound() const
{
	std::cout << "Miaou Miou Ni**a" << std::endl;
}

std::string Dog::getType() const
{
	return (this->type);
}