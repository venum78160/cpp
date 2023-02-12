#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << _name << "Jehovah's witnesses have struck again" << std::endl;
	std::cout << _name << "The world sees a new zombie appear." << std::endl
	<< "You can call him " << _name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " choked on a carrot and died... What a miserable death" << std::endl;
}

void Zombie::annoncement(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}