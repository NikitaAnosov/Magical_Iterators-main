#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include <vector>
using std::vector;
/*
operations:
• Default constructor
• Copy constructor
• Destructor
• Assignment operator
• Equality comparison (operator==)
• Inequality comparison (operator!=)
*/
namespace ariel{
    class MagicalContainer {
    private:
        vector<int> elements;
    public:
        void addElement(int element);
        void removeElement(int element);
        int size() const;
        class AscendingIterator;
        class DescendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator {
    private:
        const MagicalContainer& container;
        vector<int> sortedElements;
    public:
        AscendingIterator(const MagicalContainer& container);//Default constructor
        AscendingIterator(const AscendingIterator& other);//Copy constructor
        ~AscendingIterator() = default;//Destructor
        vector<int>::iterator begin() ;
        vector<int>::iterator end();
        //operators
        AscendingIterator& operator=(const AscendingIterator& other);//Assignment operator
        bool operator==(const AscendingIterator& other) const{return false;}//Equality comparison (operator==)
        bool operator!=(const AscendingIterator& other) const{return false;}//Inequality comparison (operator!=)
        bool operator>(const AscendingIterator& other) const{return false;}//GT
        bool operator<(const AscendingIterator& other) const{return false;}//LT
        
    };

    class MagicalContainer::DescendingIterator {
    private:
        const MagicalContainer& container;
        vector<int> sortedElements;

    public:
        DescendingIterator(const MagicalContainer& container);
        DescendingIterator(const DescendingIterator& other);
        ~DescendingIterator() = default;
        vector<int>::iterator begin();
        vector<int>::iterator end();
        //operators
        DescendingIterator& operator=(const DescendingIterator& other);
        bool operator==(const DescendingIterator& other) const {return false;}
        bool operator!=(const DescendingIterator& other) const{return false;}
        bool operator>(const DescendingIterator& other) const{return false;}
        bool operator<(const DescendingIterator& other) const{return false;}
    };

    class MagicalContainer::SideCrossIterator {
    private:
        const MagicalContainer& container;
        vector<int> crossElements;
    public:
        SideCrossIterator(const MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator() = default;
        vector<int>::iterator begin();
        vector<int>::iterator end();
        //operators
        SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const{return false;}
        bool operator!=(const SideCrossIterator& other) const{return false;}
        bool operator>(const SideCrossIterator& other) const{return false;}
        bool operator<(const SideCrossIterator& other) const{return false;}
    };

    class MagicalContainer::PrimeIterator {
    private:
        const MagicalContainer& container;
        vector<int> primeElements;
    public:
        PrimeIterator(const MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator() = default;
        vector<int>::iterator begin();
        vector<int>::iterator end();
        //operators
        PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const{return false;}
        bool operator!=(const PrimeIterator& other) const{return false;}
        bool operator>(const PrimeIterator& other) const{return false;}
        bool operator<(const PrimeIterator& other) const{return false;}
    };
}
#endif