#ifndef ORDERSHEWROTE_ORDER_HPP
#define ORDERSHEWROTE_ORDER_HPP
#include <iostream>
#include <ordershewrote/item.hpp>

class Order {
public:
    virtual int size() const = 0;
};

class Bogo : public Order {
private:
    Item PayItem;
    Item FreeItem;
public:
    Bogo(const Item &payItem, const Item &freeItem)
        : PayItem(payItem), FreeItem(freeItem) {}
    int size() const override {
        return 2;
    }
};

template <typename Item>
class Node {
public:
    Item value;
    Node* next;
};

class FlexibleOrder : public Order {
private:
    int count;
    Node<Item>* head = nullptr;
public:
    FlexibleOrder();
    void add(const Item& item);
    void remove(const Item& item);
    int size() const override;
    ~FlexibleOrder();
};

#endif

