#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "A new ScavTrap appear." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " ScavTrap has just appeared" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap	&copy) : ClapTrap(copy)
{
	std::cout << name << " ScavTrap photocopy just showed up" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name <<" ScavTrap is retiring from this world" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& op)
{
	ClapTrap::operator=(op);
	std::cout << "a new ScavTrap join the army" << std::endl;
	return(*this);
}

void ScavTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
	if (hit_point > 0 && energie_point > 0)
		std::cout << "...\"this attack was performed by Scavtrap " << name << "\"" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "Hodor !!! Hodor !! ... hum hum sorry, ScavTrap : " << name << " hold the door" << std::endl;
}

