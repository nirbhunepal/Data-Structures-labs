#include <cassert>
#include <iomanip>
#include <iostream>
#include <gossiper/gossiper.hpp>
#include <stack/stack.hpp>

int main() {

  // Stack-specific unit tests.
  Stack<int> testing_stack{};

  bool exception_caught{false};

  try {
    auto peeked = testing_stack.peek();
  } catch (const invalid_peek_error &ip) {
    exception_caught = true;
  }
  assert(("Invalid peek error was not thrown when the user peek'd an empty stack.", exception_caught));

  exception_caught = false;

  for (int i = 0; i<10; i++) {
    testing_stack.push(i);
  }
  assert(("Array invalidly contains elements!", testing_stack.size() == 10));

  for (int i = 0; i<10; i++) {
    auto discarded = testing_stack.pop();
  }

  assert(("Array invalidly contains elements!", !testing_stack.size()));

  try {
    auto peeked = testing_stack.pop();
  } catch (const invalid_pop_error &ip) {
    exception_caught = true;
  }
  assert(("Invalid pop error was not thrown when the user pop'd an empty stack.", exception_caught));

  // GossipGraph tests -- rely on proper operation of the stack.
  bool debug = false;
  int number_of_gossipers{15};
  GossiperGraph basic_gg{number_of_gossipers};
  GossiperGraph diagonal_gg{number_of_gossipers};

  basic_gg.link(0, 2);
  basic_gg.link(0, 1);
  basic_gg.link(2, 3);
  basic_gg.link(3, 4);

  for (int i = 0; i < number_of_gossipers - 1; i++) {
    diagonal_gg.link(i, i + 1);
  }

  basic_gg.print_gossiper_graph();
  diagonal_gg.print_gossiper_graph();

  if (basic_gg.can_gossip(0, 5, debug)) {
    std::cout
        << "Oops: Algorithm indicates 0 and 5 can gossip but they cannot.\n";
  } else {
    assert((false, "Oops!"));
  }
  if (basic_gg.can_gossip(1, 3, debug)) {
    std::cout << "Success ... 1 and 3 can gossip.\n";
  } else {
    assert((false, "Oops!"));
  }
  if (basic_gg.can_gossip(3, 1, debug)) {
    std::cout << "Success ... 3 and 1 can gossip.\n";
  } else {
    assert((false, "Oops!"));
  }
  if (basic_gg.can_gossip(0, 4, debug)) {
    std::cout << "Success ... 0 and 4 can gossip!\n";
  } else {
    assert((false, "Oops!"));
  }
  if (basic_gg.can_gossip(4, 0, debug)) {
    std::cout << "Success ... 4 and 0 can gossip!\n";
  } else {
    assert((false, "Oops!"));
  }
  if (basic_gg.can_gossip(2, 4, debug)) {
    std::cout << "Success ... 2 and 4 can gossip!\n";
  } else {
    assert((false, "Oops!"));
  }
  if (basic_gg.can_gossip(4, 2, debug)) {
    std::cout << "Success ... 4 and 2 can gossip!\n";
  } else {
    assert((false, "Oops!"));
  }

  for (int i = 1; i < number_of_gossipers; i++) {
    if (diagonal_gg.can_gossip(0, i)) {
      std::cout << "Success ... 0 and " << i
                << " can gossip (in the diagonal gg)!\n";
    } else {
      assert((false, "Oops!"));
    }
  }

  return 0;
}
