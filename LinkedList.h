#pragma once
#include <iostream>

struct Node
{
    double data;
    Node* next;
};

struct LinkedList
{
    Node* root = nullptr;
    void push(double data);
    void print();
    double pop();
};

void LinkedList::push(double data) {
    Node *node = new Node;
    node->data = data;
    node->next = this->root;
    this->root = node;
}

double LinkedList::pop() {
    if (this->root != nullptr) {
        double nodeData = this->root->data;
        Node *temp = this->root;
        this->root = this->root->next;
        delete temp;
        return nodeData;
    }
    else return 0;
}

void LinkedList::print() {
    Node *pos = this->root;
    while (pos != nullptr)
    {
        std::cout<<pos->data;
        pos = pos->next;
    }
}
