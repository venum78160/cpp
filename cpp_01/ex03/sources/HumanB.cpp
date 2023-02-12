#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	_weapon = NULL;
	std::cout << _name << " joined the battle." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << _name << " is dead. Let's pray he doesn't become a zombie." << std::endl;
}

void	HumanB::attack() const
{
	if (_weapon == NULL)
		std::cout << _name << " attacks with their bare hand." << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	_weapon = &Weapon;
	std::cout << _name << " is equipped with a " << _weapon->getType() << std::endl;
}