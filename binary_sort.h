#pragma once

#include <iostream>
#include <set>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void binary_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    using type = typename std::iterator_traits<Iterator_T>::value_type;

    struct entry {
        entry *left;
        entry *right;

        type key;
        type value;
    };

    std::set<entry> sorted_tree = {};

    if (sorted_tree.size() == 0) {
        sorted_tree.insert(*begin);
        begin++;
    }

    for (; begin != end; begin++) {

    }
}