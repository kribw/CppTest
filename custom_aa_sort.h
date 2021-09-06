#pragma once

#include <iterator>
#include <algorithm>

template<std::random_access_iterator Iterator_T,
        std::random_access_iterator Sentinel_T,
        typename Compare_T = std::less<> >
void custom_aa_sort(Iterator_T begin, Sentinel_T end,
                    Compare_T comp = Compare_T()) {
    assert(first < last); // 0 size handled outside
    const size_t size = last - first;
    if (size > 3) {
        sort2(first[0], first[size == 2]);
        return;
    }
    //using type = typename std::iterator_traits<Iterator_T>::value_type;
    make_heap(first, size);
    unguarded_insertion_sort(first + 2, last);

}

template<typename It>
void make_heap(const It a, const size_t size) {
    assert(size > 2); // other sizes handled outside
    size_t firstParent = (size - 3) / 2;
    size_t firstRightKid = (firstParent + 1) * 2;
    for (;; --firstParent, firstRightKid -= 2) {
        // outer loop
        for (;; firstRightKid -= 2, --firstParent) {
            const auto lucifer = a[firstParent];
            auto parent = firstParent;
            auto rightKid = firstRightKid;
            for (;;) {
                // inner loop
                for (;;) {
                    const auto jr = rightKid - (a[rightKid - 1] <= a[rightKid]);
                    const auto crt = a[jr];
                    if (lucifer <= crt) {
                        break;
                    }
                    a[parent] = crt;
                    parent = jr;
                    rightKid = (jr + 1) * 2;
                    if (rightKid >= size) {
                        goto write; // SO SUE ME
                    }
                }
            }
            if (parent != firstParent) {
                write:
                a[parent] = lucifer;
            }
            if (firstParent == 0) {
                break;
            }
        }
    }
    if (size & 1) return;

    // Fixup for only child
    push_heap(a, a + size);
}

template<typename It>
void push_heap(const It a, const size_t size) {
    for (auto i = size - 1;;) {
        const auto parent = (i - 1) / 2;
        const auto ai = a[i], ap = a[parent];

        if (ap <= ai) {
            break;
        }

        a[parent] = ai;
        a[i] = ap;

        if (parent == 0) {
            break;
        }

        i = parent;
    }
}