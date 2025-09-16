#ifndef BEADEDBAG_BEADEDBAG_HPP
#define BEADEDBAG_BEADEDBAG_HPP

#include <string>
#include <vector>

/**
 * \class Shippable
 *
 * Anything that is shippable must have a volume and a name. 
 */

class Shippable {


public:

  /**
   * get_volume()
   *
   * Get the volume of the item shipped.
   *
   * \return The volume of the item shipped.
   */
  virtual double get_volume() const = 0;

  /**
   * get_name()
   *
   * Get the name of the item shipped.
   *
   * \return The name of the item shipped.
   */
  virtual std::string get_name() const = 0;
};

/**
 * \class FastFashionPackage
 *
 * A FastFashionPackage is a Shippable item where
 * every item has a name and a volume. 
 *
 */

class FastFashionPackage : public Shippable {
private:
    std::string name;
    double volume;
public:
    FastFashionPackage(std::string name, double volume) : name(name), volume(volume) {}
    double get_volume() const override {
        return volume;
    }
    std::string get_name() const override {
        return name;
    }
};
class Electronics : public Shippable {
    private:
    std::string name;
    public:
    Electronics(const std::string& item_name) : name(item_name) {}
    double get_volume() const override {
        return 4.0;
    }
    std::string get_name() const override {
        return name;
    }

};
template <typename T>
class Teu {
    private:
    std::string destination;
    double max_volume;
    std::vector<T> items;

public:
  Teu(std::string address, double max_volume)
      : destination(address), max_volume(max_volume) {}

  std::string get_manifest() const {
      std::string manifest;
      for (size_t i = 0; i < items.size(); ++i) {
          manifest += items[i].get_name();
          if (i < items.size() - 1) {
              manifest += ", ";
          }
      }

    return manifest;

  }
    double get_tonnage() const {
      double total = 0.0;
      for (const auto& item : items) {
          total += item.get_volume();
      }
      return total;
  }

  bool add_to_container(const T& item) {
      double currentVolume = get_tonnage();
      if (currentVolume + item.get_volume() <= max_volume) {
          items.push_back(item);
          return true;
      }
        return false;
  }
};

#endif
