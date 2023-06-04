#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("MagicalContainer"){
    MagicalContainer container;
    SUBCASE("addElement/removeElement/size"){
        CHECK(container.size() == 0);
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        CHECK(container.size() == 3);
        container.addElement(9);
        CHECK_NOTHROW(container.addElement(3));
        CHECK(container.size() == 5);
        container.removeElement(17);
        container.removeElement(2);
        CHECK(container.size() == 3);
        container.removeElement(25);
        container.removeElement(9);
        CHECK_NOTHROW(container.removeElement(3));
        CHECK(container.size() == 0);
        CHECK_THROWS(container.removeElement(3));
    }
}

TEST_CASE("Custom iterators"){
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);

    MagicalContainer::AscendingIterator ascIter(container);
    SUBCASE("AscendingIterator"){
        SUBCASE("sort check"){
            // Sort: 2,3,9,17,25
            CHECK(*ascIter == 2);
            CHECK_NOTHROW(++ascIter);
            CHECK(*ascIter == 3);
            ++ascIter;
            CHECK(*ascIter == 9);
            ++ascIter;
            CHECK(*ascIter == 17);
            ++ascIter;
            CHECK(*ascIter == 25);
        }
        SUBCASE("operators"){
        MagicalContainer::AscendingIterator ascIter2(container);
        CHECK_EQ(ascIter.begin() , ascIter);// 2 == 2
        CHECK(ascIter == ascIter2);// 2 == 2
        ++ascIter2;
        CHECK(ascIter != ascIter2);// 2 != 3
        CHECK(ascIter < ascIter2); // 2 < 3
        ++ascIter;
        ++ascIter;
        CHECK(ascIter > ascIter2); // 9 > 3
        ++ascIter;
        ++ascIter;
        CHECK_EQ(ascIter.end(), ascIter); // 25 == 25
        }
    }

    MagicalContainer::DescendingIterator descIter(container);
    SUBCASE("DescendingIterator"){
        SUBCASE("sort check"){
            // Sort: 25,17,9,3,2
            CHECK(*descIter == 25);
            CHECK_NOTHROW(++descIter);
            CHECK(*descIter == 17);
            ++descIter;
            CHECK(*descIter == 9);
            ++descIter;
            CHECK(*descIter == 3);
            ++descIter;
            CHECK(*descIter == 2);
        }
        SUBCASE("operators"){
        MagicalContainer::DescendingIterator descIter2(container);
        CHECK_EQ(descIter.begin() , descIter);// 25 == 25
        CHECK(descIter == descIter2);// 25 == 25
        ++descIter2;
        CHECK(descIter != descIter2);// 25 != 17
        CHECK(descIter > descIter2); // 25 > 17
        ++descIter;
        ++descIter;
        CHECK(descIter < descIter2); // 9 < 17
        }
    }

    MagicalContainer::SideCrossIterator sideCrossIter(container);
    SUBCASE("SideCrossIterator"){
        SUBCASE("sort check"){
             // 2 25 3 17 9
            CHECK(*sideCrossIter == 2);
            ++sideCrossIter;
            CHECK(*sideCrossIter == 25);
            ++sideCrossIter;
            CHECK(*sideCrossIter == 3);
            CHECK_NOTHROW(++sideCrossIter);
            CHECK(*sideCrossIter == 17);
            ++sideCrossIter;
            CHECK(*sideCrossIter == 9);
        }
        SUBCASE("operators"){
        MagicalContainer::SideCrossIterator sideCrossIter2(container);
        CHECK_EQ(sideCrossIter.begin() , sideCrossIter);// 2 == 2
        CHECK(sideCrossIter == sideCrossIter2);// 2 == 2
        ++sideCrossIter2;
        CHECK(sideCrossIter != sideCrossIter2);// 2 != 25
        CHECK(sideCrossIter < sideCrossIter2); // 2 < 25
        ++sideCrossIter;
        ++sideCrossIter2;
        CHECK(sideCrossIter > sideCrossIter2); // 25 > 3
        }
    }

    MagicalContainer::PrimeIterator primeIter(container);
    SUBCASE("PrimeIterator"){
        SUBCASE("sort check"){
        // Sort: 2,3,17
            CHECK(*primeIter == 2);
            ++primeIter;
            CHECK(*primeIter == 3);
            ++primeIter;
            CHECK(*primeIter == 17);
        }
    SUBCASE("operators"){
        MagicalContainer::PrimeIterator primeIter2(container);
        CHECK_EQ(primeIter.begin() , primeIter);
        CHECK(primeIter == primeIter2);// 2 == 2
        ++primeIter2;
        CHECK(primeIter != primeIter2);// 2 != 3
        CHECK(primeIter < primeIter2); // 2 < 3
        CHECK_NOTHROW(++primeIter);
        ++primeIter;
        CHECK(primeIter > primeIter2); // 17 > 3
        CHECK_EQ(primeIter.end() , primeIter);
        CHECK_THROWS(++primeIter);//17 is the last prime number
        }
    }
}