#include <iterator>
#include <iostream>
#include <vector>
#include "counting_sort.h"
#include "radix_sort.h"
#include "binary_sort.h"

int main() {
    std::vector<int> my_vector = {12, 2, 3, 500, 4, 5, 2, 2, 123, 4, -51, 12, 3, 6, 9, -5};
    std::cout << "My_vector (size " << my_vector.size() << "): ";
    for(auto item : my_vector) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;

    auto begin = my_vector.begin();
    auto end = my_vector.end();

    //counting_sort(begin, end);
    //radix_sort(my_vector.begin(), my_vector.end());
    binary_sort(begin, end);

    std::cout << "After sort: ";
    for (; begin != end; begin++) {
        std::cout << *begin << ", ";
    }

    return 0;
}