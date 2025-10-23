#include <ordershewrote/item.hpp>
#include <ordershewrote/order.hpp>

FlexibleOrder::~FlexibleOrder() {
    Node<Item>* current = head;
    while (current != nullptr) {
        Node<Item>* next = current->next;
        delete current;
        current = next;
    }
}

FlexibleOrder::FlexibleOrder() {
    head = nullptr;
    count = 0;
}

int FlexibleOrder::size() const {
    return count;
}

void FlexibleOrder::add(const Item& item) {
    Node<Item>* node = new Node<Item>;
    node->value = item;
    node->next = nullptr;
    Node<Item>* current = head;
    if (head == nullptr) {
        head = node;
        count++;
        return;
    }
    while (current->next != nullptr) {
        if (current->value == item) {
            delete node;
            return;
        }
        current = current->next;
    }
    if (current->value == item) {
        delete node;
        return;
    }
    current->next = node;
    node->next = nullptr;
    count++;
}

void FlexibleOrder::remove(const Item &item) {
    Node<Item>* current = head;
    Node<Item>* previous = nullptr;
    if (current->value == item) {
        head = head->next;
        delete current;
        count--;
        return;
    }
    while (current != nullptr) {
        if (current->value == item) {
            previous->next = current->next;
            delete current;
            count--;
            return;
        }
       previous = current;
        current = current->next;

    }
}
