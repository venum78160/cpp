#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("unknown_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = ClapTrap::name;
	std::cout << "DiamondTrap: Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->hit_point = 100;
	this->energie_point = 50;
	this->attac_damage = 30;
	std::cout << "DiamondTrap: Constructor with name called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Default destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and associated Clap Trap name is ";
	std::cout << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(std::string str)
{
	ScavTrap::attack(str);
}