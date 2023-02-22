#include "../includes/Easyfind.hpp"


int main( void )
{
	std::list<int> list1;
	std::vector<int> vec;
	list1.push_back(2);
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(42);
	list1.push_back(666);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(42);
	vec.push_back(666);
	try
	{
		std::cout << "The value has been found " <<*(easyfind(list1, 42)) << std::endl;
		std::cout << "The value has been found " <<*(easyfind(vec, 666)) << std::endl;
		(easyfind(vec, 12));
	}
	catch(const std::exception& e)
	{
		std::cout << "In the catch" << std::endl;	
		std::cerr << e.what() << '\n';
	}
	return 0;
}