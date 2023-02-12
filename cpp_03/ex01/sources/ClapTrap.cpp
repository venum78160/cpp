#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Unknow";
	hit_point = 100;
	energie_point = 50;
	attac_damage = 20;
	std::cout << "Step right up folks, the one and only Claptrap is in the house and ready to cause chaos!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hit_point = 100;
	energie_point = 50;
	attac_damage = 20;
	std::cout << "Step right up folks, the one and only Claptrap is in the house and ready to cause chaos!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap	&copy)
{
	this->name = copy.name;
	hit_point = copy.hit_point;
	energie_point = copy.energie_point;
	attac_damage = copy.attac_damage;
	std::cout << "Hold onto your butts, folks, because the Claptrap revolution has just begun and there's now twice the Claptrap to love!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "It is with great sadness that I announce the passing of the one and only Claptrap. He will be greatly missed, but his memory will live on forever." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& op)
{
	this->name = op.name;
	hit_point = op.hit_point;
	energie_point = op.energie_point;
	attac_damage = op.attac_damage;
	std::cout << "Ladies and Gentlemen, hold on tight, because the Claptrap army is now at full strength! Be prepared to face twice the amount of Claptraps you were used to!" << std::endl;
	return(*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
		std::cout << "Looks like Claptrap's out of lives, but don't worry folks, I'll just respawn and be back to cause more trouble in no time!" << std::endl;
	else if(energie_point <= 0)
		std::cout << "Attention all, this is your friendly neighborhood Claptrap, reporting a critical battery low. I apologize for the inconvenience, but I must shut down until further notice" << std::endl;
	else
	{
		std::cout << "Claptrap activating attack sequence! Stand back, enemies, and feel the full force of my fury!" << std::endl;
		std::cout << "\"ClapTrap " << name << " attacks " << target <<" , causing " << attac_damage << " points of damage!\"" << std::endl;
		energie_point--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point <= 0)
		std::cout << "Looks like Claptrap's out of lives, but don't worry folks, I'll just respawn and be back to cause more trouble in no time!" << std::endl;
	else
	{
		std::cout << "Claptrap has sustained damage, but don't worry, I'm still operational! I'll just have to work a little harder to kick your butt now." << std::endl;
		std::cout << "\"ClapTrap " << name << " take " << amount <<" points of damage!\"" << std::endl;
		hit_point -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point <= 0)
		std::cout << "Looks like Claptrap's out of lives, but don't worry folks, I'll just respawn and be back to cause more trouble in no time!" << std::endl;
	else if(energie_point <= 0)
		std::cout << "Attention all, this is your friendly neighborhood Claptrap, reporting a critical battery low. I apologize for the inconvenience, but I must shut down until further notice" << std::endl;
	else
	{
		std::cout << "Claptrap is currently under maintenance, please stand by while I fix myself up and come back even better than before!" << std::endl;
		std::cout << "\"ClapTrap " << name << " repair " << amount << "\""<<std::endl;
		energie_point--;
		if (hit_point + amount >= 10)
			hit_point = 10;
		else
			hit_point += amount;
	}
}