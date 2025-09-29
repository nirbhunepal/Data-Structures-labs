#ifndef PALANYDROME_ISPALANYDROME_HPP
#define PALANYDROME_ISPALANYDROME_HPP
#include <vector>

template <typename T>
bool isPalanydromeBlueprint(const std::vector<T>& vec, size_t i, size_t length) {
    if (i >= length / 2) {
        return true;
    }
    if (vec[i] != vec[length - i - 1]) {
        return false;
    }
    return isPalanydromeBlueprint(vec, i + 1, length);
}

template <typename T>
bool isPalanydrome(const std::vector<T>& vec) {
    return isPalanydromeBlueprint(vec, 0, vec.size());
}



#endif