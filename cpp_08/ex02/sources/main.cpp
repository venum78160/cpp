#include "../includes/MutantStack.hpp"

int main()
{
    // création d'une pile de type int
    MutantStack<int> m_stack;

    // ajout d'éléments
    m_stack.push(1);
    m_stack.push(24);
    m_stack.push(36);
    m_stack.push(42);

    // parcours avec un itérateur
    MutantStack<int>::iterator it = m_stack.begin();
    MutantStack<int>::iterator ite = m_stack.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    // parcours inversé avec un itérateur
	std::cout << "reverse iterator" << std::endl;
    MutantStack<int>::reverse_iterator rit = m_stack.rbegin();
    MutantStack<int>::reverse_iterator rite = m_stack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // suppression de tous les éléments
    while (!m_stack.empty())
    {
        std::cout << "Popped: " << m_stack.top() << std::endl;
        m_stack.pop();
    }

    return 0;
}