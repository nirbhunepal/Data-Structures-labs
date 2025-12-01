#include "1klies/selectionsort.hpp"
#include <1klies/mergesort.hpp>
#include <1klies/quicksort.hpp>
#include <1klies/result.hpp>
#include <1klies/utilities.hpp>
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

using namespace std::chrono_literals;

enum class ToSortConfiguration { Ascending, Descending, Random };

std::string ToSortConfiguration_to_string(ToSortConfiguration config) {
  switch (config) {
  case ToSortConfiguration::Ascending:
    return "Ascending";
  case ToSortConfiguration::Descending:
    return "Descending";
  case ToSortConfiguration::Random:
    return "Random";
  default:
    assert(false);
  }
  __builtin_unreachable();
}

int main() {

  bool debug = false;
  bool show_progress = true;
  for (auto sorting_configuration : std::vector<ToSortConfiguration>{
           ToSortConfiguration::Ascending, ToSortConfiguration::Descending,
           ToSortConfiguration::Random}) {

    std::vector<std::tuple<std::string, std::string, Sorter<int> *>>
        configurations;

    Mergesorter<int> *mergesort = new Mergesorter<int>(debug);
    Selectionsorter<int> *selectionsort = new Selectionsorter<int>(debug);
    Quicksorter<int> *quicksort = new Quicksorter<int>(debug);

    configurations.push_back(std::make_tuple(
        "mergesort" + ToSortConfiguration_to_string(sorting_configuration) +
            ".csv",
        "Merge Sort - " + ToSortConfiguration_to_string(sorting_configuration),
        mergesort));
    configurations.push_back(std::make_tuple(
        "selectionsort" + ToSortConfiguration_to_string(sorting_configuration) +
            ".csv",
        "Selection Sort - " +
            ToSortConfiguration_to_string(sorting_configuration),
        selectionsort));
    configurations.push_back(std::make_tuple(
        "quicksort" + ToSortConfiguration_to_string(sorting_configuration) +
            ".csv",
        "Quick Sort - " + ToSortConfiguration_to_string(sorting_configuration),
        quicksort));
    for (auto c : configurations) {

      if (show_progress) {
        std::cout << "Working " << std::get<1>(c) << ".\n";
      }

      std::unique_ptr<Result> output;
      try {
        output = std::make_unique<Result>(std::get<0>(c), std::get<1>(c));
      } catch (const std::invalid_argument &) {
        std::cout << "Could not open " << std::get<0>(c)
                  << " for storing speed test results.\n";
        assert(false);
      }

      int min_size_to_sort = 10;
      int max_size_to_sort = 1000;
      int max_trials = 10;

      for (int size_to_sort = min_size_to_sort; size_to_sort < max_size_to_sort;
           size_to_sort++) {

        std::chrono::nanoseconds accumulated_sort_time = 0ns,
                                 accumulated_check_time = 0ns;

        for (int trial_number = 0; trial_number < max_trials; trial_number++) {
          std::vector<int> tosort(size_to_sort);
          std::vector<int> sorted(size_to_sort);

          fill_with_random(tosort);
          std::copy(tosort.begin(), tosort.end(), sorted.begin());
          std::sort(sorted.begin(), sorted.end());

          if (sorting_configuration == ToSortConfiguration::Ascending) {
            // Give the algorithms a (ascending) sorted list.
            std::sort(tosort.begin(), tosort.end());
          } else if (sorting_configuration == ToSortConfiguration::Descending) {
            // Give the algorithms a (descending) sorted list.
            std::sort(tosort.begin(), tosort.end());
            std::reverse(tosort.begin(), tosort.end());
          }

          if (debug) {
            log_vector_contents(std::cout, "tosort before sorting: ", tosort);
          }

          auto before_sort = std::chrono::high_resolution_clock::now();
          (*(std::get<2>(c)))(tosort);
          auto after_sort = std::chrono::high_resolution_clock::now();

          accumulated_sort_time += (after_sort - before_sort);

          if (debug) {
            log_vector_contents(std::cout, "tosort after sorting: ", tosort);
          }
          auto before_check = std::chrono::high_resolution_clock::now();
          assert(are_equal(tosort, sorted));
          auto after_check = std::chrono::high_resolution_clock::now();

          accumulated_check_time += (after_check - before_check);
        }

        auto average_sort_time = accumulated_sort_time / max_trials;
        auto average_check_time = accumulated_check_time / max_trials;

        output->add_entry(size_to_sort, average_sort_time, debug);
      }
      output->write();
    }
  }
  return 0;
}