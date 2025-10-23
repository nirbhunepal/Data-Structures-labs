#ifndef ORDERSHEWROTE_CANCOURIERTAKE_HPP
#define ORDERSHEWROTE_CANCOURIERTAKE_HPP

#include "order.hpp"

inline bool canCourierTake(const Order &order, int courierCapacity) {
    return order.size() <= courierCapacity;
}

#endif
