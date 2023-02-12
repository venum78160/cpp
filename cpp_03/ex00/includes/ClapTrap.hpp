#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string name;
	int			hit_point;
	int			energie_point;
	int			attac_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap	&copy);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap& op);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};
