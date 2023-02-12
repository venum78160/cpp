#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
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
