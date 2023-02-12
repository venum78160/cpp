#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "an WrongCat has just appeared" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->type = type;
	std::cout << "an WrongCat has just appeared" << std::endl;
}

WrongCat::WrongCat(const WrongCat	&copy)
{
	this->type = copy.type;
	std::cout << "an WrongCat has just appeared" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "an WrongCat just died" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& op)
{
	this->type = op.type;
	std::cout << "an WrongCat has just appeared" << std::endl;
	return(*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Cock-a-doodle-doo" << std::endl;
}

std::string WrongCat::getType() const
{
	return (this->type);
}