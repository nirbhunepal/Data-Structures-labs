#include <iostream>
#include <coin.h>
#include <gradable.h>

const double AUCTION_OVERHEAD_FEE = 0.89;

double sell (Gradable for_sale) {
    for_sale.Grade();

    for_sale.Value();

    return for_sale.getPrice() * AUCTION_OVERHEAD_FEE;
}


int main() {
    Coin double_eagle{"Dee Onalduck", 2023, 1849, "Washington, DC", "Gold", true};

    double price_for_coin{sell(double_eagle)};

    std::cout << "The University's endowment now has $"
              << price_for_coin
              << " more money.\n";
}
