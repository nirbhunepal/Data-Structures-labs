#include <ordershewrote/order.hpp>
#include <ordershewrote/item.hpp>
#include <ordershewrote/cancouriertake.hpp>

#include <iostream>


int main() {

  Bogo bogo_order{Item{"dryer sheets"}, Item{"hand soap"}};
  FlexibleOrder flexible_order{};

  if (canCourierTake(bogo_order, 2)) {
    std::cout << "Courier can take the Bogo order!\n";
  }

  flexible_order.add(Item{"dryer sheets"});
  flexible_order.add(Item{"hand soap"});
  flexible_order.add(Item{"dish towel"});
  flexible_order.add(Item{"Mountain Dew"});

  if (canCourierTake(flexible_order, 3)) {
    std::cout << "Courier can take the Flexible Order!\n";
  }
}