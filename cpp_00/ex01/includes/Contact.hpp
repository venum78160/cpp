#ifndef CONTACT_HPP
#define CONTACT_HPP

# include "PhoneBook.hpp"

class Contact
{
private:
	int				_index;
	std::string		_first_name;
	std::string		_last_name;
	std::string		_nickname;
	std::string		_phone_number;
	std::string		_darkest_secret;
public:
	Contact();
	~Contact();
	void	fill_info(int i);
	void	display_search(void) const;
	void	display_contact(void) const;
	std::string	getter_name(void) const;
};

#endif