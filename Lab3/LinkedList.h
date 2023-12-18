#pragma once
#include <iostream>
#include <stdexcept>

// Структура для узла односвязного списка
struct Node
{
    double data; // Значение узла
    Node* next; // Указатель на следующий узел
};

// Структура для представления односвязного списка
struct LinkedList
{
    Node* root = nullptr; // Указатель на корень списка

    // Функция для добавления нового узла в начало списка
    void push(double data);

    // Функция для удаления и извлечения значения из начала списка
    double pop();

    // Функция для вывода значений списка на экран
    void print();
};

void LinkedList::push(double data) {
    try {
        // Создаем новый узел
        Node *node = new Node;
        node->data = data; // Присваиваем ему значение
        node->next = this->root; // Устанавливаем указатель на текущий корень списка
        this->root = node; // Новый узел становится корнем списка
    } catch (std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
}

double LinkedList::pop() {
    try {
        if (this->root != nullptr) {
            double nodeData = this->root->data; // Запоминаем значение корневого узла
            Node *temp = this->root; // Сохраняем указатель на корневой узел
            this->root = this->root->next; // Перемещаем корень на следующий узел
            delete temp; // Удаляем предыдущий корневой узел
            return nodeData; // Возвращаем значение удаленного узла
        }
        else return 0; // Если список пуст, возвращаем 0
    } catch (std::exception& e) {
        std::cerr << "Error in pop(): " << e.what() << std::endl;
        return 0;
    }
}

void LinkedList::print() {
    try {
        Node *pos = this->root; // Указатель для перебора узлов списка, начинаем с корня
        while (pos != nullptr)
        {
            std::cout<<pos->data; // Выводим значение текущего узла
            pos = pos->next; // Переходим к следующему узлу
        }
    } catch (std::exception& e) {
        std::cerr << "Error in print(): " << e.what() << std::endl;
    }
}