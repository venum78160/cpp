#include "../includes/PhoneBook.hpp"

void	help(void)
{
	std::cout << "ADD    :" << std::endl;
	std::cout << "	to add a contact to your phonebook." << std::endl;
	std::cout << "SEARCH :" << std::endl;
	std::cout << "	to display your contacts." << std::endl;
	std::cout << "EXIT   :" << std::endl;
	std::cout << "	to say goodbye" << std::endl;
	std::cout << "	Warning : All your contacts will be lost permanently " << std::endl << std::endl;
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	std::cout << "Hello, welcome to your phonebook" << std::endl << std::endl;
	help();
	while (1)
	{
		std::cout << "Waiting for your orders, onii chan 👉👈" << std::endl;
		std::getline(std::cin, cmd);
		check_for_eof();
		if(cmd == "ADD")
			phonebook.addcontact();
		else if(cmd == "SEARCH")
			phonebook.searchcontact();
		else if(cmd == "EXIT")
		{
			std::cout << "Goodbye :)" << std::endl;
			return(0);
		}
		else
			help();
	}
	return (0);
}