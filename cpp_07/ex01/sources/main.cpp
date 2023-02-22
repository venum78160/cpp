#include "../includes/Iter.hpp"

int main( void )
{
	int			intArray[3] = {42, 52, 420};
	double		dblArray[3] = {4.2, 52.0, 420.0};
	std::string	strArray[3] = {"Palmi", "Yoshi", "Tac"};

	iter(intArray, 3, print<int>);
	std::cout << std::endl;
	iter(dblArray, 3, print<double>); 
	std::cout << std::endl;
	iter(strArray, 3, print<std::string>);
	std::cout << std::endl;
}