#include "../includes/Harl.hpp"


int main(int argc, char **argv)
{
	Harl Karen;
	if (argc == 2)
		Karen.complain(argv[1]);
	else
	{
		std::cout << "please enter one of the following filter levels" << std::endl;
		std::cout << "DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	return 0;
}