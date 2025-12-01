#ifndef __1KLIES__SORT_HPP
#define __1KLIES__SORT_HPP

#include <vector>

template <typename Type> class Sorter {
public:
  virtual void operator()(std::vector<Type> &tosort) = 0;
};

#endif
