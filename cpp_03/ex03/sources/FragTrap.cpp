#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "A new FragTrap appear." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " FragTrap has just appeared" << std::endl;
}

FragTrap::FragTrap(const FragTrap	&copy) : ClapTrap(copy)
{
	std::cout << name << " FragTrap photocopy just showed up" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << name <<" FragTrap is retiring from this world" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& op)
{
	ClapTrap::operator=(op);
	std::cout << "a new FragTrap join the army" << std::endl;
	return(*this);
}

void FragTrap::attack(const std::string& target)
{
	ClapTrap::attack(target);
	if (hit_point > 0 && energie_point > 0)
		std::cout << "...\"this attack was performed by FragTrap " << name << "\"" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Fragtrap " << name << " requesting high-five! Who's ready to give me some robotic love?" << std::endl;
}

