#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"



int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	j->makeSound();	//will output the dog sound!
	i->makeSound(); //will output the cat sound!
	k->makeSound();	//will output the WrongAnimal sound!
	meta->makeSound();
	delete meta;
	delete j;
	delete k;
	delete i;
	return 0;
}