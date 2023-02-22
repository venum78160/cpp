#include "../includes/Array.hpp"

int main()
{
	Array<int> def;
	// Tries to assign a value even if the array is NULL
	try
	{
		def[42] = 42;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	Array<int> test(20);
	int	size = test.size();
	// Assigns index integer value in the array, until the end
	for (int i = 0; i < size; i++)
		test[i] = i;
	int i;
	// Prints the array to ensure previous actions worked correctly
	for (i = 0; i < size - 1; i++)
		std::cout << test[i] << " ";
	std::cout << test[i] << std::endl;
	
	// Duplicate test using copy constructor
	Array<int> test2(test);
	
	// Try to edit an unexisting value in test
	try
	{
		test[20] = 42;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	// Change last value in test
	test[19] = 42;
	for (i = 0; i < size - 1; i++)
		std::cout << test[i] << " ";
	std::cout << test[i] << std::endl;
	// Changes didn't affect test2
	for (i = 0; i < size - 1; i++)
		std::cout << test2[i] << " ";
	std::cout << test2[i] << std::endl;

	// It works with other types as well
	Array<char> test3(10);
	size = test3.size();
	for (int i = 0; i < size; i++)
		test3[i] = i + 48;
	for (i = 0; i < size - 1; i++)
		std::cout << static_cast<char>(test3[i]) << " ";
	std::cout << static_cast<char>(test3[i]) << std::endl;
}