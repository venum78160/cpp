#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "God created a " << _type << " to help you in your battles" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "God gives but also takes away... "
		"The " << _type << " broke at the most opportune moment." << std::endl;
}

std::string Weapon::getType() const
{
	return(_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}