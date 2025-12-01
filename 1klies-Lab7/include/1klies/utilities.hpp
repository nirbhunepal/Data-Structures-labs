#ifndef __1KLIES_UTILITIES_HPP
#define __1KLIES_UTILITIES_HPP

#include <random>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

template <typename Type>
bool are_equal(const std::vector<Type> &left, const std::vector<Type> &right) {
  return std::equal(left.begin(), left.end(), right.begin());
}

template <typename Type>
Type fill_with_random(std::vector<Type> &tofill) {
  std::mt19937 rng;
  rng.seed((uint64_t)time(nullptr));

  Type actual_max = std::numeric_limits<Type>::min();
  std::generate(tofill.begin(), tofill.end(),
                [&actual_max, &rng, &tofill = std::as_const(tofill)]() {
                  Type current = std::abs((Type)(rng() % (tofill.size() * 2)));
                  // Be careful, we may not get something other than 0 here
                  // when we have very small haystack sizes. So, we will at
                  // least do a 1.
                  actual_max = std::max(actual_max, std::max(1, current));
                  return current;
                });
  return actual_max;
}

template <typename Type>
void log_vector_contents(std::ostream &where, const std::string &label, const std::vector<Type> &tolog) {
  where << label << "\n";
  for (auto e : tolog) {
    where << e << ", ";
  }
  where << "\n";
}

#endif
