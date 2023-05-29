#include "MagicalContainer.hpp"

using namespace ariel;

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() const {
    return elements.size();
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : container(container) {
    sortedElements = container.elements;
    std::sort(sortedElements.begin(), sortedElements.end());
}

vector<int>::const_iterator MagicalContainer::AscendingIterator::begin() const {
    return sortedElements.begin();
}

vector<int>::const_iterator MagicalContainer::AscendingIterator::end() const {
    return sortedElements.end();
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    : container(container) {
    AscendingIterator ascIter(container);
    DescendingIterator descIter(container);

    auto ascIt = ascIter.begin();
    auto descIt = descIter.begin();
    int count = 0;
    int maxSize = container.size() / 2;

    while (ascIt != ascIter.end() && descIt != descIter.end() && count < maxSize) {
        crossElements.push_back(*ascIt);
        ++ascIt;
        crossElements.push_back(*descIt);
        ++descIt;
        ++count;
    }
}

std::vector<int>::const_iterator MagicalContainer::SideCrossIterator::begin() const {
    return crossElements.begin();
}

std::vector<int>::const_iterator MagicalContainer::SideCrossIterator::end() const {
    return crossElements.end();
}



MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
    : container(container) {
    for (int element : container.elements) {
        bool isPrime = true;
        if (element < 2) {
            isPrime = false;
        } else {
            for (int i = 2; i * i <= element; ++i) {
                if (element % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            primeElements.push_back(element);
        }
    }
}

vector<int>::const_iterator MagicalContainer::PrimeIterator::begin() const {
    return primeElements.begin();
}

vector<int>::const_iterator MagicalContainer::PrimeIterator::end() const {
    return primeElements.end();
}

MagicalContainer::DescendingIterator::DescendingIterator(const MagicalContainer& container)
    : container(container) {
    sortedElements = container.elements;
    std::sort(sortedElements.rbegin(), sortedElements.rend());
}

std::vector<int>::const_iterator MagicalContainer::DescendingIterator::begin() const {
    return sortedElements.begin();
}

std::vector<int>::const_iterator MagicalContainer::DescendingIterator::end() const {
    return sortedElements.end();
}