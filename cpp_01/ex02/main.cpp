#include <iostream>
#include <string>

int main(void)
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << &brain << " " << stringPTR << " " << &stringREF << std::endl;
	std::cout << brain << " " << *stringPTR << " " << stringREF << std::endl;
	return (EXIT_SUCCESS);
}