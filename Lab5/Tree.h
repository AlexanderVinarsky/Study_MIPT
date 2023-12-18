#include "TreeNode.h"

// Класс списка на дереве
template <typename T>
class Tree {
private:
    TreeNode<T>* root; // Указатель на корень дерева

public:
    // Конструктор по умолчанию
    Tree() : root(nullptr) {}

    // Деструктор для освобождения памяти
    ~Tree() {
        destroyTree(root);
    }

    // Рекурсивный метод для освобождения памяти
    void destroyTree(TreeNode<T>* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Метод для добавления элемента в дерево
    void insert(const T& value) {
        root = insertRec(root, value);
    }

    // Рекурсивный метод для добавления элемента в дерево
    TreeNode<T>* insertRec(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    // Метод для вывода содержимого дерева в порядке возрастания
    void printInOrder() const {
        printInOrderRec(root);
        std::cout << std::endl;
    }

    // Рекурсивный метод для вывода содержимого дерева в порядке возрастания
    void printInOrderRec(TreeNode<T>* node) const {
        if (node) {
            printInOrderRec(node->left);
            std::cout << node->data << " ";
            printInOrderRec(node->right);
        }
    }
};