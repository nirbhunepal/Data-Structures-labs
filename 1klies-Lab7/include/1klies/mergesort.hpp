#ifndef __1KLIES_MERGESORT_HPP
#define __1KLIES_MERGESORT_HPP

#include <1klies/sort.hpp>
#include <1klies/utilities.hpp>
#include <cassert>
#include <iostream>

template <typename Type> class Mergesorter : public Sorter<Type> {
public:
    Mergesorter(bool debug = false) : m_debug(debug) {}

    void operator()(std::vector<Type> &tosort) {
        if (tosort.size() <=1) {
            return;
        }
        mergesort(tosort, 0, tosort.size() - 1);
    };

private:
    bool m_debug;

    void mergesort(std::vector<Type> &tosort, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;
        mergesort(tosort, left, mid);
        mergesort(tosort, mid + 1, right);
        merge(tosort, left, mid, right);
    }

    void merge(std::vector<Type> &tosort, int left, int mid, int right) {
        std::vector<Type> merged;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (m_debug) {
                std::cout << i << " " << mid << " " << j << std::endl;
            }
            if (tosort[i] <= tosort[j]) {
                merged.push_back(tosort[i]);
                ++i;
            }
            else {
                merged.push_back(tosort[j]);
                ++j;
            }
        }
        while (i <= mid) {
            merged.push_back(tosort[i]);
            ++i;
        }
        while (j <= right) {
            merged.push_back(tosort[j]);
            ++j;
        }
        for (int k =0; k < static_cast<int>(merged.size()); ++k) {
            tosort[left + k] = merged[k];
        }
    }
};

#endif


