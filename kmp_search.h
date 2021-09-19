#pragma once

#include <iterator>
#include <algorithm>
#include <span>

namespace kmp {
    template<std::forward_iterator Iterator_T, std::forward_iterator Sentinel_T>
    std::vector<int> create_lps_table(Iterator_T begin, Sentinel_T end) {
        std::span pattern = std::span(begin, end);
        std::vector<int> lps_table(std::distance(begin, end));

        // Create LPS table to use in KMP algorithm
        for (int i = 1, j = 0; i < lps_table.size(); ++i) {
            if (pattern[i] == pattern[j]) {
                lps_table[i] = ++j;
            } else {
                if (j != 0) {
                    j = lps_table[j - 1];
                    --i;
                }
            }
        }
        return lps_table;
    }

    template<std::forward_iterator Iterator_T, std::forward_iterator Sentinel_T,
            std::forward_iterator S_Iterator_T, std::forward_iterator S_Sentinel_T,
            typename BinaryPredicate_T = std::equal_to<>>
    Iterator_T kmp_search(Iterator_T begin, Sentinel_T end, S_Iterator_T s_begin,
                          S_Sentinel_T s_end, BinaryPredicate_T pred = BinaryPredicate_T()) {
        int text_length = std::distance(begin, end);
        int pattern_length = std::distance(s_begin, s_end);

        auto text = std::span(begin, end);
        auto pattern = std::span(s_begin, s_end);

        std::vector<int> lps_table = create_lps_table(s_begin, s_end);

        int matches = 0;

        for (auto it_text = text.begin(); it_text != text.end(); ++it_text) {
            auto it_begin = begin;

            for (auto it_pattern = pattern.begin(); it_pattern != pattern.end(); ++it_pattern) {
                if (pred(*it_text, *it_pattern)) {
                    if (matches == 0) {
                        int moves = std::distance(text.begin(), it_text);
                        it_begin = begin + moves;
                    }
                    ++matches;
                    ++it_text;
                } else {
                    int pattern_index = std::distance(pattern.begin(), it_pattern);
                    if (pattern_index != 0) {
                        int index = lps_table[pattern_index - 1];

                        if (index == 0) {
                            matches = 0;
                            --it_text;
                            break;
                        }
                        it_pattern = pattern.begin() + index - 1;
                    } else {
                        matches = 0;
                        break;
                    }
                }

                if (matches == pattern_length) {
                    return it_begin;
                }
            }

            if (matches == pattern_length) {
                return it_begin;
            }
        }

        /*for (int i = 0, j = 0; i < text_length; ++i) {
            if (pattern[j] == text[i]) {
                continue;
            }

            if (j == pattern_length) {
                j = lps_table[j - 1];
                --i;
            } else if (i < text_length && pattern[j] != text[i]) {
                if (j != 0) {
                    --i;
                } else {
                    j = lps_table[j - 1];
                }
            }
        } */

        return end;
    }
}