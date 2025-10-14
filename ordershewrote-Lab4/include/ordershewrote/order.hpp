#ifndef ORDERSHEWROTE_ORDER_HPP
#define ORDERSHEWROTE_ORDER_HPP
#include <ordershewrote/item.hpp>


class Order {
public:
    virtual int size() const = 0;
};

class Bogo: public Order {
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

class FlexibleOrder: public Order {
private:
    Item *items;
    int count;
    int capacity;
public:
    FlexibleOrder() {
        capacity = 10;
        count = 0;
        items = new Item[capacity];
    }

    void add(const Item &item) {
        for (int i = 0; i < count; i++) {
            if (items[i] == item) {
                return;
            }
        }
        if (count == capacity) {
            int new_capacity= capacity*2;
            Item* new_items = new Item[new_capacity];
            for (int i = 0; i < count; i++) {
                new_items[i] = items[i];
            }
            delete [] items;
            items = new_items;
            capacity = new_capacity;
        }
        items[count] = item;
        count++;
    }

    void remove(const Item &itemToRemove) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (items[i] == itemToRemove) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return;
        }
        for (int i = index; i < count-1; i++) {
            items[i] = items[i+1];
        }
        count--;
    }

    int size() const override {
        return count;
    }

    ~FlexibleOrder() {
        delete [] items;
    }
};


#endif
