#ifndef __1KLIES_QUICKSORT_HPP
#define __1KLIES_QUICKSORT_HPP

#include <1klies/sort.hpp>
#include <cassert>
#include <iostream>

template <typename Type>
class Quicksorter : public Sorter<Type> {
public:
    Quicksorter(bool debug = false) : m_debug(debug) {}

    void operator()(std::vector<Type> &tosort) override {
        if (tosort.size() <= 1) {
            return;
        }
        quicksort(tosort, 0, static_cast<int>(tosort.size()) - 1);
    }

private:
    bool m_debug;

    int partition(std::vector<Type> &tosort, int left, int right) {
        Type pivot = tosort[right];
        int i = left - 1;

        for (int j = left; j < right; ++j) {
            if (tosort[j] <= pivot) {
                ++i;
                std::swap(tosort[i], tosort[j]);
            }
        }

        std::swap(tosort[i + 1], tosort[right]);
        return i + 1;
    }

    void quicksort(std::vector<Type> &tosort, int left, int right) {
        if (left >= right) {
            return;
        }

        int pivot_index = partition(tosort, left, right);

        quicksort(tosort, left, pivot_index - 1);
        quicksort(tosort, pivot_index + 1, right);
    }
};

#endif

