#include "../includes/Zombie.hpp"

int	main(void)
{
	int nbr_zombie = 5;
	Zombie *horde = zombieHorde(nbr_zombie, "billy bob");
	
	for (int i = 0; i < nbr_zombie; i++)
	{
		std::cout << "The " << i + 1 << " members of the horde will present themselves..."
			<< std::endl;
		horde[i].annoncement();
	}
	delete[] horde;
	return (EXIT_SUCCESS);
}