#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
public:
	Intern();
	Intern(const Intern	&copy);
	~Intern();
	Intern &operator=(const Intern& op);

	Form	*makeForm(std::string name, std::string target) const;
};
