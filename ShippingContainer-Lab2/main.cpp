#include <cassert>
#include <iostream>
#include <teu/teu.hpp>
#include <vector>

int main() {

  // What items are purchased and sent to my parent's house.
  FastFashionPackage tshirt{"Nirvana Tshirt", 20};
  FastFashionPackage crocs{"Crocs", 20};
  FastFashionPackage maxi{"dress", 15};

  // Load them into a shipping container addressed to them.
  Teu<FastFashionPackage> container{"1296 Mistymeadow Lane", 37};

  // Attempt to load the tshirt into the shipping container.
  // It will fit.
  if (!container.add_to_container(tshirt)) {
    std::cout << "Should have been able to put the " << tshirt.get_name()
              << " into the fast-fashion shipping container.\n";
    return -1;
  }
  // Attempt to load the crocs into the shipping container.
  // It will not fit.
  if (container.add_to_container(crocs)) {
    std::cout << "Should not have been able to put the " << crocs.get_name()
              << " into the fast-fashion shipping container.\n";
    return -1;
  };

  // Attempt to load the dress into the shipping container.
  // It will fit.
  if (!container.add_to_container(maxi)) {
    std::cout << "Should have been able to put the " << maxi.get_name()
              << " into the fast-fashion shipping container.\n";
    return -1;
  }

  // Double check that the tonnage is calculated correctly.
  if (container.get_tonnage() != 35) {
    std::cout
        << "Fast-fashion shipping container has incorrect total tonnage.\n";
    return -1;
  }

  // Double check that the manifest is truthful.
  if ("Nirvana Tshirt, dress" != container.get_manifest()) {
    std::cout << "Fast-fashion shipping manifest is incorrect.\n";
    return -1;
  }

  std::cout << "All fast-fashion shipping tests pass!\n";


  // Once you have all the tests passing above, uncomment these tests
  // to make sure that you implemented the Electronics class correctly.


  // Make a list of the electronics that Will purchased and is shipping to his house.
  Electronics karaoke_mic{"Taylor Swift Singalong Mic"};
  Electronics switch2{"Nintendo Switch 2"};
  Electronics cooker{"Sous Vide Cooker"};
  std::vector<Electronics> electronics_to_ship{karaoke_mic, switch2, cooker};

  // Ship these to Will.
  Teu<Electronics> container2{"349 Deepwoods Drive", 12};

  // Attempt to load each of the pieces of electronics into the shipping container.
  // They should all fit.
  for (const auto i : electronics_to_ship) {
    if (!container2.add_to_container(i)) {
      std::cout << "Should have been able to put the " << i.get_name()
                << " into the electronics shipping container.\n";
      return -1;
    }
  }

  // Trying to ship one too many items will breach the weight limit.
  Electronics threed{"Bambu 3d Printer"};
  if (container2.add_to_container(threed)) {
    std::cout << "Should not have been able to put the " << threed.get_name()
              << " into the electronics shipping container.\n";
    return -1;
  }

  // Double check that the tonnage is calculated correctly.
  if (container2.get_tonnage() != 12) {
    std::cout << "Electronics shipping container has incorrect total tonnage.\n";
    return -1;
  }

  // Double check that the manifest is truthful.
  if ("Taylor Swift Singalong Mic, Nintendo Switch 2, Sous Vide Cooker" !=
      container2.get_manifest()) {
    std::cout << "Electronics shipping container manifest is incorrect.\n";
    return -1;
  }

  std::cout << "All electronics shipping tests pass!\n";



  return 0;
}
