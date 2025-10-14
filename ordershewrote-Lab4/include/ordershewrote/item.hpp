#ifndef ORDERSHEWROTE_ITEM_HPP
#define ORDERSHEWROTE_ITEM_HPP

#include <string>

class Item {
public:
  Item(): m_item_name("") {};
  Item(const std::string &name) : m_item_name(name) {}
  std::string getItemName() const;
  bool operator==(const Item &other) const;
  bool operator!=(const Item &other) const;

private:
  std::string m_item_name;
};

#endif