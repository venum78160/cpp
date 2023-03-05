#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "Error: incorrect number of arguments." << std::endl;
		return (1);
	}
	std::vector<int>	m_vec;
	std::list<int>		m_list;
	try
	{
		for (int i = 1; i <  argc; i++)
		{
			int num = atoi(argv[i]);
			if (num > 0)
			{
				m_vec.push_back(num);
				m_list.push_back(num);
			}
			else
				throw std::invalid_argument("Not in valid range");
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << "Before:";
	for (std::vector<int>::iterator it = m_vec.begin(); it != m_vec.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	clock_t tv1 = clock();
    merge_insert_sort(m_vec);
    clock_t tv2 = clock();
	clock_t tl1 = clock();
    merge_insert_sort(m_list);
    clock_t tl2 = clock();
	std::cout << "After:";
	for (std::vector<int>::iterator it = m_vec.begin(); it != m_vec.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::endl;
	std::cout << "Time to sort with vector: " << (double)(tv2 - tv1) / CLOCKS_PER_SEC << " seconds" << std::endl;
	std::cout << "Time to sort with list: " << (double)(tl2 - tl1) / CLOCKS_PER_SEC << " seconds" << std::endl;
}