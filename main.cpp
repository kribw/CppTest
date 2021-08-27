#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <cmath>

template<std::random_access_iterator Iterator_T, std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<>>
void counting_sort(Iterator_T begin, Sentinel_T end, Compare_T comp = Compare_T()) {
    using type = typename std::iterator_traits<Iterator_T>::value_type;
    std::map<type, int> items = {};

    for (; begin != end; begin++) {
        items[*begin]++;
    }

    std::vector<type> sorted_items = {};
    for (auto &item: items) {
        std::cout << "key: " << item.first << " value: " << item.second << "\n";
        while (item.second > 0) {
            sorted_items.push_back(item.first);
            item.second--;
        }
    }

    begin = sorted_items.begin();
    end = sorted_items.end();

    while (begin != end) {
        std::cout << *begin << ", ";
        begin++;
    }
}

template<std::random_access_iterator Iterator_T,
        std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<> >
void binary_sort(Iterator_T begin, Sentinel_T end,
                 Compare_T comp = Compare_T()) {
    using type = typename std::iterator_traits<Iterator_T>::value_type;
    //using comp_type = typename std::iterator_traits<Compare_T>::value_type;

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

        //if ()
    }

    //std::random_access_iterator iterator = start.begin();
}

void count_sort(std::vector<int> unsorted_items, int iterations) {
    const int max = 10;
    std::vector<int> sorted_items {};
    std::vector<int> count = {};
    //int count[max] = {0};
    int place = 10 ^ iterations;

    // Create array to use in count_sort
    //int unsorted_array[unsorted_items.size()];
    //std::copy(unsorted_items.begin(), unsorted_items.end(), unsorted_array);

    // Calculate count of elements
    for (int unsorted_item : unsorted_items) {
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

template<std::random_access_iterator Iterator_T,
        std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<> >
void radix_sort(Iterator_T begin, Sentinel_T end,
                Compare_T comp = Compare_T()) {
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
        count_sort(unsorted_vector, i);
    }
}

int main() {
    std::vector<int> my_vector = {12, 2, 3, 500, 4, 5, 2, 2, 123, 4, 51, 12, 3, 6, 9};

    //counting_sort(my_vector.begin(), my_vector.end());
    radix_sort(my_vector.begin(), my_vector.end());

    return 0;
}