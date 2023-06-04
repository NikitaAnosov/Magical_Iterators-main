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

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(container);
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

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(container);
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return SideCrossIterator(container);
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

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return PrimeIterator(container);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(container);
}

MagicalContainer::DescendingIterator::DescendingIterator(const MagicalContainer &container)
    : container(container)
{
    sortedElements = container.elements;
    std::sort(sortedElements.rbegin(), sortedElements.rend());
}

MagicalContainer::DescendingIterator MagicalContainer::DescendingIterator::begin()
{
    return DescendingIterator(container);
}

MagicalContainer::DescendingIterator MagicalContainer::DescendingIterator::end()
{
    return DescendingIterator(container);
}