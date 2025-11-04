
#ifndef _GOSSIPER_HPP
#define _GOSSIPER_HPP

#include <vector>

class Gossiper {
public:
  /** Create a new gossiper.
   *
   * @param debug Whether to emit debugging information when
   * performing operations on this gossiper.
   * @post Gossiper is unvisited.
   * @post Gossiper has a valid, unique identifier.
   */
  Gossiper(bool debug = false)
      : m_gossiper_id(++m_gossiper_id_assigner), m_visited(false),
        m_debug(false) {}

  /** Whether two gossipers are equal to one another according
   * to their unique identifiers.
   *
   * @param other The target of the comparison.
   * @return true if both gossipers have the same unique id; false,
   * otherwise.
   */
  const bool operator==(const Gossiper &other) const;

  /** Whether two gossipers are unequal to one another according
   * to their unique identifiers.
   *
   * @param other The target of the comparison.
   * @return true if both gossipers have different unique ids; false,
   * otherwise.
   */
  const bool operator!=(const Gossiper &other) const;

  /** Return the id of the gossiper.
   *
   * @return The unique identifier of the gossiper.
   */
  int get_id() const { return m_gossiper_id; }

  /** Set the `visited` flag on this gossiper.
   *
   * @post The `visited` flag is set on this gossiper.
   */
  void set_visited() { m_visited = true; }

  /** Get the value of the `visited` flag of this gossiper.
   *
   * @return true if this gossiper's `visited` flag is set to
   * visisted; false, otherwise.
   */
  bool get_visited() { return m_visited; }

  /** Unset the `visited` flag of this gossiper.
   *
   * @post The `visited` flag of this gossiper is unset.
   */
  void unset_visited() { m_visited = false; }

private:
  int m_gossiper_id;
  static int m_gossiper_id_assigner;
  bool m_visited;
  bool m_debug;
};

class GossiperGraph {
public:
  /** Create the gossiper graph!
   *
   * @param size The number of gossipers in the graph.
   * @post The nodes in the gossiper graph are completely disconnected.
   * @post All gossipers are unvisited.
   * @post All gossipers have a unique id.
   */
  GossiperGraph(int size);

  /** This function will pretty print the gossiper graph to show the
   * gossipers at which indexes can communicate.
   */
  void print_gossiper_graph() const;

  /** This function will mark the gossiper graph to indicate
   * that the gossipers at indexes _gossiper1_ and _gossiper2_
   * can hear each other.
   *
   */
  void link(int gossiper1, int gossiper2);

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
  bool can_gossip(int start_gossiper, int end_gossiper,
                  bool debug = false) const;

  /** This function will release all the memory allocated
   * to the gossipers in the graph.
   *
   */
  ~GossiperGraph();

private:
  std::vector<Gossiper *> m_gossipers;
  std::vector<std::vector<bool>> m_gossiper_edges;

  /** This function will reset the `visited` flag on all
   * the gossipers in our graph.
   *
   * @post None of the gossipers in the network are marked
   * visisted.
   */
  void unset_visited() const;

  /** This function will generate a std::vector<int> of indexes of
   * the gossipers with whom _gossiper_id_ can gossip.
   *
   * @param gossiper_id The index of the source of the gossip.
   * @param debug Whether to print debugging information during execution.
   * @return A std::vector<int> with the indexes of the gossipers that the
   * gossiper with index _gossiper_id can reach.
   */
  std::vector<int> get_unvisited_neighbors_of(int gossiper_id,
                                              bool debug = false) const;
};
#endif
