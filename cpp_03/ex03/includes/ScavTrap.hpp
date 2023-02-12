#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap	&copy);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap& op);

	void guardGate();
	void attack(const std::string& target);
};
