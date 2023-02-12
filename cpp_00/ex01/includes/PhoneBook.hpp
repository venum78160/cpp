#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# define MAXCONTACT 4
# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void	addcontact(void);
	void	searchcontact(void) const;
	void	display_all(void) const;

private:

	int	_index;
	Contact _contacts[MAXCONTACT];
};

void	print_ten(std::string str);
bool    check_for_eof(void);

#endif