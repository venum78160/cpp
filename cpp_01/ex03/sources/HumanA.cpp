#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon	&weapon): _name(name) , _weapon(weapon)
{
	std::cout << _name << " joined the battle with a " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << _name << " is dead. Let's pray he doesn't become a zombie." << std::endl;
}

void	HumanA::attack() const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
