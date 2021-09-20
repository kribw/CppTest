#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include "counting_sort.h"

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void radix_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    using type = typename std::iterator_traits<Iterator_T>::value_type;
    std::vector<type> elements {};
    std::copy(begin, end, elements);

    auto max = *std::max_element(begin, end, comp);
    //int max = std::max(elements, comp);
    std::cout << "Max: " << max << std::endl;

    // Find amount of digits in max element
    //int digits = (int) std::log10(std::abs(max));
    int digits = 0;

    while(true) {
        if(comp(1 * 10^digits, max)) {
            digits++;
        } else {
            break;
        }
    }

    // stable_sort elements from least to most significant digit
    for (int i = digits; i >= 0; i--) {
        std::stable_sort(begin, end, [comp, i](auto &a, auto &b){
            return i > 0 ? comp(a % (10^i), b % (10^i)) : comp(a, b);
        });
    }
}