#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
protected:
	std::string type;
	Brain *_brain;
public:
	Dog();
	Dog(std::string type);
	Dog(const Dog	&copy);
	~Dog();
	Dog &operator=(const Dog& op);

	void makeSound() const;
	std::string getType() const;
};
