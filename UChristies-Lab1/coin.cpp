#include "coin.h"

void Coin::Grade() {
    if (m_special_coin) {
        setRating(100.0);
    } else {
        setRating(90.0);
    }
}

void Coin::Value() {
    if (m_special_coin) {
        setPrice(20e6);
    }
    else if (m_coin_material == "gold" || m_coin_material == "Gold") {
        setPrice(1890.0);
    }
    else if (m_coin_material == "silver" || m_coin_material == "Silver") {
        setPrice(25.0);
    }
    else {
        setPrice(1.0);
    }
}

