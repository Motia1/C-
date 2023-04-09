#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Stack {
public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    int top();
    bool empty();
    void clear();
    void print();
    bool hasEqualNext();
private:
    Node* head;
};