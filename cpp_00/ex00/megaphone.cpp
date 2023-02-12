#include <iostream>
#include <string>

void	my_toupper(char *str)
{
	int i = 0;

	while(str && str[i])
		std::cout << (char)toupper(str[i++]);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv++ && *argv)
		{
			my_toupper(*argv);
		}
		
	}std::cout << std::endl;
}
