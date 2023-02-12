#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if(N < 1)
		std::cout << "A horde is not really a horde without a zombie in it." << std::endl;
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setname(name);
	return (horde);
}