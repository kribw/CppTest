#pragma once

#include <iterator>
#include <algorithm>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void custom_aa_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    /*
     * There are three possible implementations that I can see,
     * not sure which is the best one and if c) is even allowed.
     * For now I'll implement c), might revisit later.
     * a) Literal copypasta of AA's algorithm from CppCon
     * b) make_heap and rotate until heap is sorted
     * c) make_heap and sort_heap (what AA's custom impl. is based off)
     */

    // Create heap
    std::make_heap(begin, end, comp);

    // b: Rotate items until heap is sorted from low -> high
    // For some reason this implementation was super slow, so I decided to scrap it.
    /*for (auto i = begin; i != end; i++) {
        std::rotate(std::upper_bound(begin, i, *i, comp), i, i + 1);
    } */

    // c: sort heap using sort_heap
    std::sort_heap(begin, end, comp);
}