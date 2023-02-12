#include "../includes/WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
	this->type = "Unknow Wronganimal";
	std::cout << "an Wronganimal has just appeared" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "an Wronganimal has just appeared" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal	&copy)
{
	this->type = copy.type;
	std::cout << "an Wronganimal has just appeared" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "an Wronganimal just died" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& op)
{
	this->type = op.type;
	std::cout << "an Wronganimal has just appeared" << std::endl;
	return(*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "***WrongAnimal sound***" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}