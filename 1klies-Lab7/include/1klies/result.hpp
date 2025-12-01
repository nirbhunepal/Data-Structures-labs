#ifndef __1KLIES__RESULT_HPP
#define __1KLIES__RESULT_HPP

#include <utility>
#include <chrono>
#include <fstream>
#include <map>
#include <string>
#include <iostream>

class Result {
public:
  Result(const std::string &result_filename, const std::string &label_name) : m_label_name(label_name) {
    m_output_fs.open(result_filename, std::ios_base::trunc);

    if (!m_output_fs.is_open()) {
      throw std::invalid_argument("Could not open result file!");
    }
  }

  void add_entry(int size, std::chrono::nanoseconds sort_time, bool verbose = false) {
    m_results[size] = sort_time;

    if (verbose) {
      std::cout << size << ", " << sort_time.count() << "\n";
    }
  }

  void write() {
    // Print out a header.
    m_output_fs << "Element Count, " << m_label_name << "\n";
    // Print out one result per line. The results will be in ascending
    // order of the number of elements in vector to sort.
    for (auto i : m_results) {
      m_output_fs << i.first << ", "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(
                         i.second)
                         .count()
                  << "\n";
    }
  }

  ~Result() {
    if (m_output_fs.is_open()) {
      m_output_fs.close();
    }
  }

private:
  std::ofstream m_output_fs;
  std::string m_label_name;
  std::map<int, std::chrono::nanoseconds> m_results;
};

#endif