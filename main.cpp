#include <iostream>
struct Node
{
    int data;
    Node* next;
};

struct LinkedList
{
    Node* root = nullptr;
    void push(int data);
    void print();
    int pop();
};

void LinkedList::push(int data) {
        Node *node = new Node;
        node->data = data;
        node->next = this->root;
        this->root = node;
}

int LinkedList::pop() {
    if (this->root != nullptr) {
        int nodeData = this->root->data;
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

int main() {
    LinkedList *linkedList = new LinkedList;
    linkedList->push(1);
    linkedList->push(2);
    std::cout<<linkedList->pop() << std::endl;
    linkedList->print();
    delete linkedList;
    return 0;
}
