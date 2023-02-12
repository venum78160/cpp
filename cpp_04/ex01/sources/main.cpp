#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"



int main()
{
	Animal *animals[10];

	for (int i = 5; i < 10; i++)
	{
		std::cout << "---------------------" << std::endl;	
		animals[i] = new Cat();
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "---------------------" << std::endl;	
		animals[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << animals[i]->getType() << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "---------------------" << std::endl;	
		delete animals[i];
	}
	return 0;
}