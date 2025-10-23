#include <ordershewrote/item.hpp>
#include <string>

bool Item::operator==(const Item &other) const {
  return other.m_item_name == m_item_name;
}

bool Item::operator!=(const Item &other) const {
  return other.m_item_name != m_item_name;
}

std::string Item::getItemName() const {
  return m_item_name;
}