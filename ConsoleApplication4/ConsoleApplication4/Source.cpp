
#include "Header.h"

Stack::Stack() {
    head = NULL;
}

Stack::~Stack() {
    clear();
}

void Stack::push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void Stack::pop() {
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

int Stack::top() {
    if (head == NULL) {
        return -1; // or some other value to indicate an empty stack
    }
    return head->data;
}

bool Stack::empty() {
    return head == NULL;
}

void Stack::clear() {
    while (!empty()) {
        pop();
    }
}

void Stack::print() {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool Stack::hasEqualNext() {
    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            return true;
        }
        current = current->next;
    }
    return false;
}