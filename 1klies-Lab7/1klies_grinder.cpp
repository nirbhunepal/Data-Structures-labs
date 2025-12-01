#include <1klies/selectionsort.hpp>
#include <1klies/mergesort.hpp>
#include <1klies/quicksort.hpp>
#include <1klies/utilities.hpp>
#include <iostream>
#include <vector>

int main() {

  bool debug = false;
  bool show_progress = false;

  std::vector<std::pair<std::string, Sorter<int> *>> configurations;
  Mergesorter<int> *mergesort = new Mergesorter<int>(debug);
  Selectionsorter<int> *selectionsort = new Selectionsorter<int>(debug);
  Quicksorter<int> *quicksort = new Quicksorter<int>(debug);

  configurations.push_back(std::make_pair("Merge sort", mergesort));
  configurations.push_back(std::make_pair("Selection sort", selectionsort));
  configurations.push_back(std::make_pair("Quick sort", quicksort));

  for (auto c : configurations) {

    std::string sort_name{c.first};

    if (show_progress) {
      std::cout << "Checking your implementation of " << sort_name << ".\n";
    }

    int grinder_length = 500;
    int trials_per_grinder_length = 20;

    for (int trial_number = 0; trial_number < trials_per_grinder_length;
         trial_number++) {
      std::vector<int> tosort(grinder_length);
      std::vector<int> sorted(grinder_length);

      fill_with_random(tosort);

      // Make sorted a copy of tosort.
      std::copy(tosort.begin(), tosort.end(), sorted.begin());
      // Now, sort it with the standard library. This will be
      // our key!
      std::sort(sorted.begin(), sorted.end());

      if (debug) {
        log_vector_contents(std::cout,
                            "tosort before sorting with " + sort_name + ": ",
                            tosort);
      }

      (*(c.second))(tosort);

      if (debug) {
        log_vector_contents(
            std::cout, "tosort after sorting with " + sort_name + ": ", tosort);
      }
      // Compare the one that we sorted with the one that the standard algorithm
      // sorted -- they should be the same!
      if (!are_equal(sorted, tosort)) {
        std::cout << "Failure sorting a list using the " << sort_name
                  << " algorithm: \n";
        log_vector_contents(std::cout, "Vector is not in order: ", tosort);
        exit(1);
      }
    }
  }
  std::cout << "Success\n";
  return 0;
}
