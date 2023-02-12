#include "../includes/PhoneBook.hpp"

Contact::Contact(/* args */)
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_darkest_secret = "";
}

Contact::~Contact()
{
}

std::string	Contact::getter_name(void) const
{
	return(_first_name);
}

void	print_ten(std::string str)
{
	std::string	space(10, ' ');
	int size;

	size = str.length();
	if (size <= 10)
		std::cout << space.substr(0, 10 - size) << str;
	else
		std::cout << str.substr(0, 9) << '.';
}

bool    check_for_eof(void)
{
    if (std::cin.eof())
    {
        std::cin.clear();
        clearerr(stdin);
        return (true);
    }
    return (false);
}

void	Contact::fill_info(int i)
{
	_index = i;
	std::cout << "Creation of a new contact" << std::endl;
	std::cout << "Please fill in the following information" << std::endl;
	while (std::cout << "First name: " << std::endl && this->_first_name.empty())
	{
		std::getline(std::cin, _first_name);
		check_for_eof();
	}
	while (std::cout << "Last name: " << std::endl && this->_last_name.empty())
	{
		std::getline(std::cin, _last_name);
		check_for_eof();
	}
	while (std::cout << "Nickname: " << std::endl && this->_nickname.empty())
	{
		std::getline(std::cin, _nickname);
		check_for_eof();
	}
	while (std::cout << "Phone number: " << std::endl && this->_phone_number.empty())
	{
		std::getline(std::cin, _phone_number);
		check_for_eof();
	}
	while (std::cout << "Darkest secret: " << std::endl && this->_darkest_secret.empty())
	{
		std::getline(std::cin, _darkest_secret);
		check_for_eof();
	}
	std::cout << "New contact added !" << std::endl;
}

void	Contact::display_contact(void) const
{
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name <<std::endl;
	std::cout << "Nickname: " << _nickname <<std::endl;
	std::cout << "Phone number: " << _phone_number <<std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}

void	Contact::display_search(void) const
{
	std::string pipe(1, '|');

	print_ten(_first_name);
	std::cout << pipe;
	print_ten(_last_name);
	std::cout << pipe;
	print_ten(_nickname);
	std::cout << pipe << std::endl;
}