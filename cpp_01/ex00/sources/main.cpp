#include "../includes/Zombie.hpp"

int	main(int argc,char **argv)
{
	if (argc < 3)
		std::cout << "please enter the names of the zombies you want to create" << std::endl;
	else
	{
		Zombie *good_zombie = newZombie(argv[1]);
		randomChump(argv[2]);
		good_zombie->annoncement();
		delete(good_zombie);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}