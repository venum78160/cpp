#include "../includes/Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *stay_zombie = new Zombie(name);
	return (stay_zombie);
}