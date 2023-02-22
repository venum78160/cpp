#include "../includes/Convert.hpp"

void	handleint(int x)
{
	std::cout << "int : " << x << std::endl;
	if (isprint(x))
		std::cout << "char : " << static_cast<char>(x) << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "float : " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(x) << ".0"<< std::endl;
}

void	handlechar(char x)
{
	int	Vint = static_cast<int>(x);
	std::cout << "valeur vint = " << Vint << std::endl;
	if (isprint(x))
		std::cout << "char : " << x << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << Vint << std::endl;
	std::cout << "float : " << static_cast<float>(Vint) << ".0f" << std::endl;
	std::cout << "double : " << static_cast<double>(Vint) << ".0"<< std::endl;
}

void	handlefloat(float x)
{
	int	Vint = static_cast<int>(x);
	std::cout << "float : " << std::fixed << std::setprecision(1) << x << "f" << std::endl;
	if (isprint(Vint))
		std::cout << "char : " << static_cast<char>(Vint) << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << Vint << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(x) << std::endl;
}

void	handledouble(double x)
{
	int	Vint = static_cast<int>(x);
	std::cout << "double : " << std::fixed << std::setprecision(1) << x << std::endl;
	if (isprint(Vint))
		std::cout << "char : " << static_cast<char>(Vint) << std::endl;
	else
		std::cout << "char : Non displayable" << std::endl;
	std::cout << "int : " << Vint << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(x) << "f" << std::endl;
}

void	handle_other( std::string &argv)
{
	if (!argv.compare("nan") || !argv.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (!argv.compare("-inf") || !argv.compare("-inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: -inf" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (!argv.compare("+inf") || !argv.compare("+inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: +inf" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (!argv.compare("inf") || !argv.compare("inff"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout <<"int: inf" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
}

int	find_type(std::string argv)
{
	std::string special_cases[8] = {"+inf", "-inf", "inf", "+inff", "-inff", "inff", "nan", "nanf"};
	for (int i = 0; i < 8; i++)
		if (argv == special_cases[i])
			handle_other(argv);

	if (argv.size() == 1)
	{
		if (isdigit(argv[0]))
			return INT;
		else if (isprint(argv[0]))
			return CHAR;
		else
		{
			std::cout << "Please use the following format: ./convert [Number]" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	int f = 0; int p = 0;
	for (size_t i = 0; i < argv.size(); i++)
	{
		if (argv[i] == '-' && i == 0)
			continue;
		else if(argv[i] == 'f')
			f++;
		else if(argv[i] == '.')
			p++;
		else if(!isnumber(argv[i]))
		{
			std::cout << "Please use the following format: ./convert [Number]" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	if(p == 1 && (argv.back() != '.' && argv.front() != '.'))
	{
		if (f == 1 && argv.back() == 'f')
			return (FLOAT);
		else if (f == 0)
			return (DOUBLE);
	}
	else if (p == 0 && f == 0)
		return (INT);
	std::cout << "Please use the following format: ./convert [Number]" << std::endl;
	exit(EXIT_FAILURE);
	return (5);
}

int main(int argc, char **argv)
{
	int type;
	if (argc != 2)
	{
		std::cout << "Please use the following format: ./convert [Number]" << std::endl;
		return (0);
	}
	std::string str = static_cast<std::string>(argv[1]);
	type = find_type(str);
	try
	{
		std::stoi(str);
	}
	catch(const std::exception& e)
	{
		std::cout << "No number outside of int limit" << std::endl;
		return (0);
	}
	switch (type)
	{
	case CHAR:
		handlechar(argv[1][0]);
		break;
	case INT:
		handleint(std::stoi(str));
		break;
	case FLOAT:
		handlefloat(std::stof(str));
		break;
	case DOUBLE:
		handledouble(std::stod(str));
		break;
	default:
		std::cout << "Erreur value" << std::endl;
		break;
	}
	return 1;
}