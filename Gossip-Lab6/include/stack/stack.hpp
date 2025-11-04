#ifndef _STACK_STACK_HPP
#define _STACK_STACK_HPP

#include <stdexcept>

class invalid_peek_error: public std::logic_error {
  public:
    invalid_peek_error(const std::string &message): std::logic_error(message) {};
};

class invalid_pop_error: public std::logic_error {
  public:
    invalid_pop_error(const std::string &message): std::logic_error(message) {};
};

template <typename StackElementType> class Stack {
    struct Node {
        StackElementType data;
        Node* next;
    };
private:
    Node* head;
    int count;


public:
    Stack() {
       head = nullptr;
       count = 0;
    }
    ~Stack() {
        Node* current = head;
        while(current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

void push(const StackElementType& data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    count++;
}
StackElementType pop() {
    if (head == nullptr) {
        throw invalid_pop_error("Cannot pop from an empty stack");
    }
    Node* current = head;
    StackElementType popped = head->data;
    head = head->next;
    delete current;
    count--;
    return popped;

}
StackElementType peek() const {
    if (head == nullptr) {
        throw invalid_peek_error("Cannot peek from an empty stack");
    };
    return head->data;
};

int size() const {
    return count;
}
};

#endif