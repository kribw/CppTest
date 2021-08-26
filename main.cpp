#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

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


int main() {
    std::vector<int> my_vector = {12, 2, 3, 4, 5, 2, 2, 123, 4, 51, 12, 3, 6, 9};
    counting_sort(my_vector.begin(), my_vector.end());
    return 0;
}