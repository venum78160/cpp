#include "../includes/Harl.hpp"

Harl::Harl(void)
{
	std::cout << "A wild Karen has just appeared in your store. Run for your life!" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "The Karen just left the store dipping her cookie in your tears." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ] This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int i = 0;
	void(Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for(; i < 4; i++)
	{
		if (str[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			(this->*ptr[0])();
			break;

		case 1:
			(this->*ptr[1])();
			break;

		case 2:
			(this->*ptr[2])();
			break;
		
		case 3:
			(this->*ptr[3])();
			break;
		
		default:
			std::cout << "Karen seems to have a voice extinction." << std::endl;
	}
}