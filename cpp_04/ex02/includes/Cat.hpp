#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
protected:
	std::string type;
	Brain *_brain;
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat	&copy);
	~Cat();
	Cat &operator=(const Cat& op);

	void makeSound() const;
	std::string getType() const;
};
