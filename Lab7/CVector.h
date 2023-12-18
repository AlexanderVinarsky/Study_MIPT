#pragma once
#include <iostream>

template <typename T>
class CVector {
class Iterator: public std::forward_iterator_tag
{
private:
    T* current;
public:

    // Конструктор итератора
    Iterator(T* pos){current = pos;};
    // Оператор разыменования
    void * operator++(){current=*(current+1);};
    // Префиксный инкремент
    bool operator==(Iterator other){return current == other.current;};
    // Оператор сравнения на неравенство
    bool operator!=(Iterator other){return *this != other;};

};
private:
    T *data; // Указатель на массив элементов
    int size; // Размер массива
    int num_elem; // Количество элементов

public:
    // Конструктор по умолчанию
    CVector() {
        data = new T[2];
        size = 2;
        num_elem = 0;
    };
    // Конструктор с указанием размера
    CVector(int m_size) {
        data = new T[2];
        m_size = m_size;
        num_elem = 0;
    };

    // Метод для добавления элемента в массив
    void append(T input) {
        try {
            if (size > num_elem) { // Если размер массива больше количества элементов
                data[num_elem] = input; // Добавляем элемент в массив
                num_elem++; // Увеличиваем количество элементов
            } else { // Иначе
                T* new_data = new T[size * 2]; // Создаем новый массив удвоенного размера
                for (int i = 0; i < num_elem; i++) { // Копируем элементы из старого массива в новый
                    new_data[i] = data[i];
                }
                delete[] data; // Удаляем старый массив
                data = new_data;  // Присваиваем указателю на массив новый массив
                size *= 2; // Увеличиваем размер массива вдвое
                data[num_elem] = input; // Добавляем новый элемент в массив
                num_elem++; // Увеличиваем количество элементов
            }
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl; // Обработка исключений
        }
    }

    // Метод для удаления элемента из массива по указанной позиции
    void pop(int pos) {
        try {
        num_elem--;
        return data[pos];
        } catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    void sort() {
        try {
            int left = 0;
            int right = num_elem - 1;
            int i = left, j = right;
            int pivot = data[(left + right) / 2]; // Выбираем опорный элемент

            while (i <= j) {
                while (data[i] < pivot)
                    i++; // Поиск элемента больше опорного слева
                while (data[j] > pivot)
                    j--; // Поиск элемента меньше опорного справа
                if (i <= j) {
                    std::swap(data[i], data[j]);
                    i++;
                    j--;
                }
            }

            if (left < j)
                quicksort(data, left, j); // Рекурсивный вызов для левой части массива
            if (i < right)
                quicksort(data, i, right);  // Рекурсивный вызов для правой части массива
        }  catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl; // Обработка исключений
        }
    }

};
