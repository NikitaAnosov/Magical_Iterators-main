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
        AscendingIterator begin() ;
        AscendingIterator end();
        //operators
        // AscendingIterator& operator=(const AscendingIterator& other);//Assignment operator
        bool operator==(const AscendingIterator& other) const{return false;}//Equality comparison (operator==)
        bool operator!=(const AscendingIterator& other) const{return false;}//Inequality comparison (operator!=)
        bool operator>(const AscendingIterator& other) const{return false;}//GT
        bool operator<(const AscendingIterator& other) const{return false;}//LT
        int operator*() const{return 0;}
        AscendingIterator& operator++() {return *this;}//++i
    };

    class MagicalContainer::DescendingIterator {
    private:
        const MagicalContainer& container;
        vector<int> sortedElements;

    public:
        DescendingIterator(const MagicalContainer& container);
        DescendingIterator(const DescendingIterator& other);
        ~DescendingIterator() = default;
        DescendingIterator begin();
        DescendingIterator end();
        //operators
        // DescendingIterator& operator=(const DescendingIterator& other);
        bool operator==(const DescendingIterator& other) const {return false;}
        bool operator!=(const DescendingIterator& other) const{return false;}
        bool operator>(const DescendingIterator& other) const{return false;}
        bool operator<(const DescendingIterator& other) const{return false;}
        int operator*() const{return 0;}
        DescendingIterator& operator++() {return *this;}
    };

    class MagicalContainer::SideCrossIterator {
    private:
        const MagicalContainer& container;
        vector<int> crossElements;
    public:
        SideCrossIterator(const MagicalContainer& container);
        SideCrossIterator(const SideCrossIterator& other);
        ~SideCrossIterator() = default;
        SideCrossIterator(SideCrossIterator&& other) noexcept = default;
        SideCrossIterator begin();
        SideCrossIterator end();
        //operators
        // SideCrossIterator& operator=(const SideCrossIterator& other);
        bool operator==(const SideCrossIterator& other) const{return false;}
        bool operator!=(const SideCrossIterator& other) const{return false;}
        bool operator>(const SideCrossIterator& other) const{return false;}
        bool operator<(const SideCrossIterator& other) const{return false;}
        int operator*() const{return 0;}
        SideCrossIterator& operator++() {return *this;}
    };

    class MagicalContainer::PrimeIterator {
    private:
        const MagicalContainer& container;
        vector<int> primeElements;
    public:
        PrimeIterator(const MagicalContainer& container);
        PrimeIterator(const PrimeIterator& other);
        ~PrimeIterator() = default;
        PrimeIterator begin();
        PrimeIterator end();
        //operators
        // PrimeIterator& operator=(const PrimeIterator& other);
        bool operator==(const PrimeIterator& other) const{return false;}
        bool operator!=(const PrimeIterator& other) const{return false;}
        bool operator>(const PrimeIterator& other) const{return false;}
        bool operator<(const PrimeIterator& other) const{return false;}
        int operator*() const{return 0;}
        PrimeIterator& operator++() {return *this;}
    };
}
#endif