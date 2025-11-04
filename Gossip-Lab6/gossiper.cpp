#include <cassert>
#include <gossiper/gossiper.hpp>
#include <iomanip>
#include <iostream>
#include <stack/stack.hpp>
#include <vector>

static int calculate_field_width(int max) {
  int width{0};
  for (; max != 0; max /= 10, width++) {
  }
  return width + 1;
}

int Gossiper::m_gossiper_id_assigner{0};

const bool Gossiper::operator==(const Gossiper &other) const {
  if (m_debug) {
    std::cout << "Running Gossiper::operator==\n";
  }
  return other.m_gossiper_id == m_gossiper_id;
}

const bool Gossiper::operator!=(const Gossiper &other) const {
  if (m_debug) {
    std::cout << "Running Gossiper::operator!=\n";
  }
  return other.m_gossiper_id != m_gossiper_id;
}

/** Create the gossiper graph!
 *
 * @param size The number of gossipers in the graph.
 * @post The nodes in the gossiper graph are completely disconnected.
 * @post All gossipers are unvisited.
 * @post All gossipers have a unique id.
 */
GossiperGraph::GossiperGraph(int size)
    : m_gossiper_edges(std::vector<std::vector<bool>>(size)),
      m_gossipers(std::vector<Gossiper *>(size)) {
  for (auto &gossiper : m_gossipers) {
    gossiper = new Gossiper();
  }
  for (auto &row : m_gossiper_edges) {
    row = std::vector<bool>(size);
  }
}

/** This function will pretty print the gossiper graph to show the
 * gossipers at which indexes can communicate.
 */
void GossiperGraph::print_gossiper_graph() const {
  int field_width{calculate_field_width(m_gossipers.size())};
  std::cout << std::setw(field_width) << "";
  for (int i = 0; i < m_gossipers.size(); i++) {
    std::cout << std::setw(field_width) << i;
  }
  std::cout << "\n";

  for (int i = 0; i < m_gossipers.size(); i++) {
    std::cout << std::setw(field_width) << i;
    for (int j = 0; j < m_gossipers.size(); j++) {
      std::cout << std::setw(field_width) << m_gossiper_edges[j][i];
    }
    std::cout << "\n";
  }
}

/** This function will mark the gossiper graph to indicate
 * that the gossipers at indexes _gossiper1_ and _gossiper2_
 * can hear each other.
 *
 */
void GossiperGraph::link(int gossiper1, int gossiper2) {
  m_gossiper_edges[gossiper1][gossiper2] = true;
  m_gossiper_edges[gossiper2][gossiper1] = true;
}

/** This function will check whether _start_gossiper_ can gossip
 * with _end_gossiper_.
 *
 * @param start_gossiper The index of the gossiper where the rumor
 * will start.
 * @param end_gossiper The index of the gossiper that _start_gossiper_
 * wants to hear the rumor.
 * @return true if the _start_gossiper_'s rumor can reach the _end_gossiper_;
 * false, otherwise.
 */
bool GossiperGraph::can_gossip(int start_gossiper, int end_gossiper,
                               bool debug) const {
  Stack<int> gossiper_path;

  gossiper_path.push(start_gossiper);

  for (; gossiper_path.size() && gossiper_path.peek() != end_gossiper;) {
    int current_gossiper_index = gossiper_path.peek();

    if (debug) {
      std::cout << "Currently investigating: " << current_gossiper_index
                << "\n";
    }
    m_gossipers[current_gossiper_index]->set_visited();
    auto neighbors_of_current_gossiper =
        get_unvisited_neighbors_of(current_gossiper_index, debug);

    if (neighbors_of_current_gossiper.size()) {
      if (debug) {
        std::cout << "Traversing to " << neighbors_of_current_gossiper[0]
                  << "\n";
      }
      gossiper_path.push(neighbors_of_current_gossiper[0]);
    } else {
      if (debug) {
        std::cout << "Backtracking from " << gossiper_path.peek() << "\n";
      }
      gossiper_path.pop();
    }
  }

  unset_visited();

  bool path_found =
      gossiper_path.size() && gossiper_path.peek() == end_gossiper;

  // If we are debugging, let's print the path that we found!
  if (debug) {
    if (path_found) {
      while (gossiper_path.size()) {
        std::cout << gossiper_path.pop() << " <- ";
      }
      std::cout << "rumor.\n";
    }
  }

  return path_found;
}

GossiperGraph::~GossiperGraph() {
  for (auto gossiper : m_gossipers) {
    delete gossiper;
  }
}

void GossiperGraph::unset_visited() const {
  // We declare this a `const` function, but it's really a lie.
  for (auto &gossiper : m_gossipers) {
    gossiper->unset_visited();
  }
}

std::vector<int>
GossiperGraph::get_unvisited_neighbors_of(int gossiper_id,
                                          bool debug) const {
  std::vector<int> neighbors{};
  for (int i = 0; i < m_gossipers.size(); i++) {
    if (m_gossiper_edges[gossiper_id][i] || m_gossiper_edges[i][gossiper_id]) {
      // Let's check to make sure that we don't push a node we have already
      // visited!
      if (!m_gossipers[i]->get_visited()) {
        neighbors.push_back(i);
      } else if (debug) {
        std::cout << "Skipping neighbor " << i
                  << " because they are already visited!\n";
      }
    }
  }
  return neighbors;
}