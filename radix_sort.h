#pragma once

#include <iostream>
#include <cmath>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void radix_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    // Find type of iterator
    using type = typename std::iterator_traits<Iterator_T>::value_type;
    // Create vector of iterator type and copy entries
    std::vector<type> unsorted_vector = {};
    std::copy(begin, end, std::back_inserter(unsorted_vector));

    // 1 - Get max element
    int max = *std::max_element(unsorted_vector.begin(), unsorted_vector.end(), comp);
    std::cout << "Max: " << max << std::endl;

    // 2 - Find amount of digits in max element
    int digits = (int) std::log10(max);
    max > 0 ? digits++ : digits--;

    // 3 - Perform counting sort x times, where x = digits
    for (int i = 1; i <= digits; i++) {
        radix_counting_sort(unsorted_vector, i);
    }
}

void radix_counting_sort(std::vector<int> unsorted_items, int iterations) {
    const int max = 10;
    std::vector<int> sorted_items{};
    std::vector<int> count = {};
    //int count[max] = {0};
    int place = 10 ^ iterations;

    // Create array to use in count_sort
    //int unsorted_array[unsorted_items.size()];
    //std::copy(unsorted_items.begin(), unsorted_items.end(), unsorted_array);

    // Calculate count of elements
    for (int unsorted_item: unsorted_items) {
        count.at((unsorted_item / place) % 10)++;
        //count[(unsorted_item / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < max; i++) {
        count.at(i) += count.at(i - 1);
        //count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    /* for (int i = unsorted_items.size() - 1; i >= 0; i--) {
        int index = count[(unsorted_items[i] / 10 ^ iterations) % 10];
        sorted_elements[index - 1] = unsorted_items[i];
        count[(unsorted_items[i] / 10 ^ iterations) % 10]--;
    } */

    for (int i = unsorted_items.size() - 1; i >= 0; i--) {
        int index = count.at((unsorted_items.at(i) / 10 ^ iterations) % 10);
        sorted_items.at(index - 1) = unsorted_items.at(i);
        count.at((unsorted_items[i] / 10 ^ iterations) % 10)--;
    }

    std::cout << "Sorted by count_sort: ";

    for (int i = 0; i < unsorted_items.size(); ++i) {
        std::cout << count.at(i) << ", ";
    }
}