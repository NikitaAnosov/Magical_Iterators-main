#include "MagicalContainer.hpp"
using namespace ariel;

void MagicalContainer::addElement(int element)
{
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element)
{
    for (auto it = elements.begin(); it != elements.end();)
    {
        if (*it == element)
        {
            it = elements.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int MagicalContainer::size() const
{
    return elements.size();
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &container)
    : container(container)
{
    sortedElements = container.elements;
    // using std::sort library function
    std::sort(sortedElements.begin(), sortedElements.end());
}

vector<int>::iterator MagicalContainer::AscendingIterator::begin()
{
    return sortedElements.begin();
}

vector<int>::iterator MagicalContainer::AscendingIterator::end()
{
    return sortedElements.end();
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &container)
    : container(container)
{
    AscendingIterator ascIter(container);
    DescendingIterator descIter(container);

    auto ascIt = ascIter.begin();
    auto descIt = descIter.begin();
    int count = 0;
    int maxSize = container.size() / 2;

    while (ascIt != ascIter.end() && descIt != descIter.end() && count < maxSize)
    {
        crossElements.push_back(*ascIt);
        ++ascIt;
        crossElements.push_back(*descIt);
        ++descIt;
        ++count;
    }
}

std::vector<int>::iterator MagicalContainer::SideCrossIterator::begin()
{
    return crossElements.begin();
}

std::vector<int>::iterator MagicalContainer::SideCrossIterator::end()
{
    return crossElements.end();
}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container)
    : container(container)
{
    for (int element : container.elements)
    {
        bool isPrime = true;
        if (element == 2)
        {
            isPrime = true;
        }
        else if (element % 2 == 0)
        {
            isPrime = false;
        }
        else{
        for (int i = 3; i * i <= element; i += 2)
        {
            if (element % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        }
        if (isPrime)
        {
            primeElements.push_back(element);
        }
    }
    std::sort(primeElements.begin(), primeElements.end());
}

vector<int>::iterator MagicalContainer::PrimeIterator::begin()
{
    return primeElements.begin();
}

vector<int>::iterator MagicalContainer::PrimeIterator::end()
{
    return primeElements.end();
}

MagicalContainer::DescendingIterator::DescendingIterator(const MagicalContainer &container)
    : container(container)
{
    sortedElements = container.elements;
    std::sort(sortedElements.rbegin(), sortedElements.rend());
}

std::vector<int>::iterator MagicalContainer::DescendingIterator::begin()
{
    return sortedElements.begin();
}

std::vector<int>::iterator MagicalContainer::DescendingIterator::end()
{
    return sortedElements.end();
}