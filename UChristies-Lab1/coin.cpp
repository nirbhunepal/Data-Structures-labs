#include "coin.h"

void Coin::Value() {
    if (m_special_coin) {
        setPrice(20e6);
    } else if (m_coin_material == "gold") {
        setPrice(1890);
    } else if (m_coin_material == "silver") {
        setPrice(23.85);
    } else {
        setPrice(10);
    }
}

void Coin::Grade() {
    setRating(100);
}
