#pragma once

#include <iostream>
#include <map>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void counting_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    // Get type from iterator
    using type = typename std::iterator_traits<Iterator_T>::value_type;

    // Sort the items with counting sort using a map
    std::map<type, int, Compare_T> items(comp);

    // Add items to map
    for (auto i = begin; i != end; i++) {
        items[*i]++;
    }

    // Update the iterator with the sorted values
    for (auto &item: items) {
        while (item.second > 0 && begin != end) {
            *begin = item.first;
            item.second--;
            begin++;
        }
    }
}