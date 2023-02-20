#include "../includes/Data.hpp"

uintptr_t serialize(Data *ptr)
{
	uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
	return result;
}

Data *deserialize(uintptr_t raw)
{
	Data *result = reinterpret_cast<Data *>(raw);
	return result;
}

int main()
{
	Data x;
	x.value = 42;
	std::cout << &x << std::endl;
	std::cout << x.value << std::endl;

	Data *other = deserialize(serialize(&x));
	
	std::cout << other << std::endl;
	std::cout << other->value << std::endl;
}