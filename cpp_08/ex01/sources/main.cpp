#include "../includes/Span.hpp"

int main( void )
{
	Span test(1);
	try
	{
		test.addNumber(42);
		test.addNumber(43);
		test.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << "end first catch " << e.what() << '\n';
	}
	
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "----------------------" << std::endl;

	std::vector<int> vec(5);
	std::iota(vec.begin(), vec.end(), 1);
	try
	{
		Span test2(15);
		test2.addNumberRange(vec.begin(), vec.end());
		test2.printVec();
		test2.addNumberRange(vec.begin(), vec.end());
		test2.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << "In catch NumberRange "<<e.what() << '\n';
	}
	return (0);
}