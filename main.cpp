#include <iterator>
#include <iostream>
#include "sort.h"

int main() {
    std::vector<int> my_vector = {12, 2, 3, 500, 4, 5, 2, 2, 123, 4, -51, 12, 3, 6, 9, -5};
    counting_sort(my_vector.begin(), my_vector.end());
    //radix_sort(my_vector.begin(), my_vector.end());

    return 0;
}