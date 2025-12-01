#ifndef __1KLIES_INSERTIONSORT_HPP
#define __1KLIES_INSERTIONSORT_HPP

#include <1klies/sort.hpp>
#include <cassert>

template <typename Type>
class Selectionsorter : public Sorter<Type> {
public:
    Selectionsorter(bool debug = false) : m_debug(debug) {}

    void operator()(std::vector<Type> &tosort) override {
        int n = static_cast<int>(tosort.size());
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;

            for (int j = i + 1; j < n; ++j) {
                if (tosort[j] < tosort[minIndex]) {
                    minIndex = j;
                }
            }

            std::swap(tosort[i], tosort[minIndex]);
        }
    }

private:
    bool m_debug;
};

#endif
