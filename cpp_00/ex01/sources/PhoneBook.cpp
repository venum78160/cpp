
#include "../includes/PhoneBook.hpp"

void	PhoneBook::addcontact(void)
{
	if (_index < MAXCONTACT)
	{
		_contacts[_index].fill_info(_index);
		_index++;
	}
	else
	{
		for(int i = 0; i < MAXCONTACT - 1; i++)
			_contacts[i] = _contacts[i + 1];
		_contacts[MAXCONTACT - 1].fill_info(MAXCONTACT - 1);
	}
}

void	header_shearch(void)
{
	std::string	header;
	std::string	line(43, '-');

	header += "     Index|";
	header += "First Name|";
	header += " Last Name|";
	header += "  Nickname";
	std::cout << header << std::endl << line << std::endl;
}

void	PhoneBook::display_all(void) const
{
	for(int i = 0; i < MAXCONTACT; i++)
	{
		if (_contacts[i].getter_name() == "")
		{
			if (i == 0)
				std::cout << "You don't have any contact at the moment." << std::endl;
			break;
		}
		std::cout << "         " << i + 1 << "|";
		_contacts[i].display_search();
	}
}

void	PhoneBook::searchcontact(void) const
{
	std::string	cmd;

	if (_contacts[0].getter_name() != "")
		header_shearch();
	display_all();
	while (_contacts[0].getter_name() != "" && std::cout << "Which contact would you like to see?" << std::endl && std::getline(std::cin, cmd))
	{
		check_for_eof();
		try {
			if (stoi(cmd) - 1 >= 0 && stoi(cmd) - 1 < MAXCONTACT &&_contacts[std::stoi(cmd) - 1].getter_name() != "")
			{
				_contacts[std::stoi(cmd) - 1].display_contact();
				std::cout << "Press Y to view another contact." << std::endl;
				std::cout << "Press anything else to return to the menu." << std::endl;
				std::getline(std::cin, cmd);
				if (cmd != "Y" && cmd != "y")
					return;
			}
			else
			{
				std::cout << "You have entered " << cmd <<", it does not correspond to any contact." << std::endl;
				std::cout << "Please enter the index of the desired contact in the list below." << std::endl;
				header_shearch();
				display_all();
			}
		}
		catch (const std::exception &e) {
			std::cout << "error: " << e.what() << std::endl;
			std::cout << "Please enter a valid input" << std::endl;
			header_shearch();
			display_all();
		}
	}
	std::cout << std::endl;
}

PhoneBook::PhoneBook()
{
	_index = 0;
}

PhoneBook::~PhoneBook()
{
}
