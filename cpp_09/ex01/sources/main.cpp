#include "../includes/RPN.hpp"

void	case_operator(std::stack<int> *my_stack, char *token)
{
	if ((*my_stack).size() < 2)
	{
		std::cerr << "Error: missing operands in the stack." << std::endl;
		exit (1);
	}
	int second = (*my_stack).top(); (*my_stack).pop();
	int first = (*my_stack).top(); (*my_stack).pop();
	switch (token[0])
	{
	case '+':
		(*my_stack).push(first + second);
		break;
	case '-':
		(*my_stack).push(first - second);
		break;
	case '*':
		(*my_stack).push(first * second);
		break;
	case '/':
		if (second == 0)
		{
			std::cerr << "Error: division by zero." << std::endl;
			exit (1);
        }
		(*my_stack).push(first / second);
		break;
	default:
		std::cerr << "Error: Problem with operator" << std::endl;
		exit (1);
		break;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: incorrect number of arguments." << std::endl;
		return (1);
	}
	std::stack<int> my_stack;

	char *token = std::strtok(argv[1], " ");
	while (token != NULL)
	{
		if(isdigit(token[0]))
		{
			int num = atoi(token);
			std::cerr << "Debug[]: num = "<< num << " my_stack.size = "<< my_stack.size()<< std::endl;
			if (num >= 0 && num <= 9)
			{
				std::cerr << "Debug[]: here num = " << num << std::endl;
				my_stack.push(num);
			}
			else if (num < 100 && num >= 0 && my_stack.size() == 0)
			{
				my_stack.push(num / 10);
				my_stack.push(num % 10);
			}
			else
			{
				std::cerr << "Error: numbers must be less than 10. num ="<< num << std::endl;
				return (1);
			}
		}
		else if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
			case_operator(&my_stack, token);
		else
		{
			std::cerr << "Error: invalid token => "<< token << std::endl;
				return (1);
		}
		token = strtok(NULL, " ");
	}
	if (my_stack.size() != 1)
		{
			std::cerr << "Missing an operator"<< token << std::endl;
				return (1);
		}
	std::cout << my_stack.top() << std::endl;
	return (0);
}