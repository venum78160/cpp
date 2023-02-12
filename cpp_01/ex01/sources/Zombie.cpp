#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A new zombie has joined the horde" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " choked on a carrot and died... What a miserable death" << std::endl;
}

void Zombie::annoncement(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
}