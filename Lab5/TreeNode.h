#pragma once
#include <iostream>

// Класс узла дерева
template <typename T>
class TreeNode {
public:
    T data; // Данные узла
    TreeNode* left; // Указатель на левого потомка
    TreeNode* right; // Указатель на правого потомка

    // Конструктор с параметрами
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};
