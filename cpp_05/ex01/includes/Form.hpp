#pragma once
#include <iostream>
#include <string>
#include <Bureaucrat.hpp>

class Bureaucrat;

class Form
{
private:
	std::string const	_name;
	int	const			_requiredSignGrade;
	int	const			_requiredExecuteGrade;
	bool				_issigned;
public:
	Form();
	Form(std::string name, int SGrade, int EGrade);
	Form(const Form	&copy);
	~Form();
	Form &operator=(const Form& op);

	std::string	const	getName() const;
    int getRequiredSignGrade() const;
    int getRequiredExecuteGrade() const;
    bool getIsSigned() const;

	void	beSigned(Bureaucrat const &worker);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "The Grade exceeds the acceptable limit! Allowed range: [1, 150]";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return "The Grade falls below the minimum limit! Allowed range: [1, 150]";
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &obj);