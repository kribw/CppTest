#pragma once

#include <iostream>
#include <set>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void binary_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    // Get type from iterator
    using type = typename std::iterator_traits<Iterator_T>::value_type;

    // Binary Insertion Sort using a multiset (BST, allows duplicate values)
    std::multiset<type, Compare_T> sorted(comp);

    // Insert values from iterator into BST
    for (auto i = begin; i != end; ++i) {
        sorted.insert(*i);
    }

    // Set iterator values to sorted values from BST
    for (auto &item : sorted) {
        *begin = item;
        begin++;
    }
}