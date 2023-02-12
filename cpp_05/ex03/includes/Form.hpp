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
	virtual ~Form();
	Form &operator=(const Form& op);

	std::string	const	getName() const;
    int getRequiredSignGrade() const;
    int getRequiredExecuteGrade() const;
    bool getIsSigned() const;

	void	beSigned(Bureaucrat const &worker);
	virtual void	execute(Bureaucrat const & executor) const;
	virtual void	makeit(void) const = 0;

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
	class AnyExecption : public std::exception
	{
		public:
		std::string _message;
		AnyExecption(const std::string &message) throw(): _message(message) {}
		virtual ~AnyExecption(void) throw(){};
		const char *what() const throw()
		{
			return _message.c_str();
		}
	};
};

std::ostream &operator<<(std::ostream &o, Form const &obj);