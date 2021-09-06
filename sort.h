#pragma once

#include "vector"

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T, typename Compare_T = std::less<>>
void counting_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T());

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T, typename Compare_T = std::less<>>
void binary_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T());

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T, typename Compare_T = std::less<>>
void radix_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T());

void radix_counting_sort(std::vector<int> unsorted_items, int iterations);