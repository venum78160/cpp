#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap	&copy);
	~FragTrap();
	FragTrap &operator=(const FragTrap& op);

	void highFivesGuys();
	void attack(const std::string& target);
};
