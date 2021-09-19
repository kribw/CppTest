#include <iterator>
#include <iostream>
#include <vector>
#include "counting_sort.h"
#include "radix_sort.h"
#include "binary_sort.h"
#include "custom_aa_sort.h"
#include "naive_search.h"
#include "kmp_search.h"
#include <functional>
#include <span>

using namespace kmp;

int main() {
    std::vector<int> my_vector = {12, 2, 3, 500, 4, 5, 2, 2, 123, 4, -51, 12, 3, 6, 9, -5};
    auto begin = my_vector.begin();
    auto end = my_vector.end();

    //custom_aa_sort(begin, end);
    //radix_sort(begin, end);
    //std::stable_sort(begin, end, std::less<>());

    /* for (auto item : my_vector) {
        std::cout << item << ", ";
    } */

    std::string sequence = "s2ring";
    std::string string = "HEL2LO in this string HELLO Find the sequence";

    //auto result = naive_search(string.begin(), string.end(), sequence.begin(), sequence.end());
    auto result = kmp_search(string.begin(), string.end(), sequence.begin(), sequence.end());

    std::cout << "Result: " << *result << std::endl;
    std::cout << "Result == end: " << (result == string.end() ? "true" : "false");

    return 0;
}
