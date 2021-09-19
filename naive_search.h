#pragma onceonce

// stl
#include <iterator>
#include <algorithm>

template<std::forward_iterator Iterator_T, std::forward_iterator Sentinel_T,
        std::forward_iterator S_Iterator_T,
        std::forward_iterator S_Sentinel_T,
        typename BinaryPredicate_T = std::equal_to<>>
Iterator_T naive_search(Iterator_T begin, Sentinel_T end,
                        S_Iterator_T s_begin, S_Sentinel_T s_end,
                        BinaryPredicate_T pred = BinaryPredicate_T()) {
    // If sequence is empty, return begin
    if (s_begin == s_end) {
        return begin;
    }

    // Count characters in sequence
    int characters = std::distance(s_begin, s_end);

    // Iterate through each character and check for match
    for (; begin != end; ++begin) {
        // Found a match
        if (pred(*begin, *s_begin)) {
            int matches = 0;

            // Count matches in string and sequence
            for (auto it_begin = begin, it_s_begin = s_begin;
                 it_s_begin != s_end && it_begin != end; ++it_s_begin, ++it_begin) {
                // Mismatch, cancel loop and move on to next char in "begin" iterator
                if (!pred(*it_begin, *it_s_begin)) {
                    break;
                }
                matches++;
            }
            // If matches equal to characters in string, we have a match
            // return current position of match
            if (matches == characters) {
                return begin;
            }
        }
    }
    // No match
    return end;
}