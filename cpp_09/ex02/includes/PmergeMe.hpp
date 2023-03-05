#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iterator>

template <typename cont>
void merge(cont& ct, cont& cont1, cont& cont2)
{
    typename cont::iterator it = ct.begin();
    typename cont::const_iterator it1 = cont1.begin();
    typename cont::const_iterator it2 = cont2.begin();

    while (it1 != cont1.end() && it2 != cont2.end())
    {
        if (*it1 < *it2)
        {
            *it = *it1;
            ++it1;
        }
        else
        {
            *it = *it2;
            ++it2;
        }
        ++it;
    }

    while (it1 != cont1.end())
    {
        *it = *it1;
        ++it;
        ++it1;
    }

    while (it2 != cont2.end())
    {
        *it = *it2;
        ++it;
        ++it2;
    }

    cont1.clear();
    cont2.clear();
}

// Sort a container using merge-insert sort algorithm
template <typename cont>
void merge_insert_sort(cont& ct)
{
    if (ct.size() > 1)
    {
		cont cont1(ct.begin(), std::next(ct.begin(), ct.size() / 2));
        cont cont2(std::next(ct.begin(), ct.size() / 2), ct.end());

        merge_insert_sort(cont1);
        merge_insert_sort(cont2);

        merge(ct, cont1, cont2);
    }
}