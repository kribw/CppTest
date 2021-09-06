#pragma once

#include <iostream>
#include <map>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void counting_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    using type = typename std::iterator_traits<Iterator_T>::value_type;
    std::map<type, int, Compare_T> items(comp);

    // Keep track of iterator steps in order to go back to the beginning
    int iterator_steps = 0;
    // Sort the items with counting sort using a map
    for (; begin != end; begin++) {
        items[*begin]++;
        iterator_steps++;
    }

    // Put the sorted items into a vector
    std::vector<type> sorted_items = {};
    for (auto &item: items) {
        std::cout << "key: " << item.first << " value: " << item.second << "\n";
        while (item.second > 0) {
            sorted_items.push_back(item.first);
            item.second--;
        }
    }

    // Return iterator to beginning
    begin -= iterator_steps;

    auto sorted_begin = sorted_items.begin();
    // Update the iterator with the sorted values
    for (; begin != end ; begin++) {
        *begin = *sorted_begin;
        sorted_begin++;
    }
}