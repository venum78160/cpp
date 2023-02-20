#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base	*generate( void )
{
	srand(time(0));
	unsigned int	randint = rand() % 3;
	Base			*ret;

	switch (randint)
	{
		case 0:
			ret = new A; break;
		case 1:
			ret = new B; break;
		default:
			ret = new C; break;
	}
	return (ret);
}

void identify(Base* p)
{
	A *testA = dynamic_cast<A *>(p);
	if (testA)
	{
		std::cout << "The true nature of the object is A" << std::endl;
		return;
	}
	B *testB = dynamic_cast<B *>(p);
	if (testB)
	{
		std::cout << "The true nature of the object is B" << std::endl;
		return;
	}
	C *testC = dynamic_cast<C *>(p);
	if (testC)
	{
		std::cout << "The true nature of the object is C" << std::endl;
		return;
	}
	std::cout << "The true nature of the object is quite different" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &test = dynamic_cast<A &>(p);
		(void)test;
		std::cout << "The true nature of the object is A" << std::endl;
	}
	catch(const std::bad_cast &bc)
	{}
	try
	{
		B &test = dynamic_cast<B &>(p);
		(void)test;
		std::cout << "The true nature of the object is B" << std::endl;
	}
	catch(const std::bad_cast &bc)
	{}
	try
	{
		C &test = dynamic_cast<C &>(p);
		(void)test;
		std::cout << "The true nature of the object is C" << std::endl;
	}
	catch(const std::bad_cast &bc)
	{}
}

int main()
{
	Base *rand = generate();
	identify(rand);
	identify(*rand);
	delete rand;
}