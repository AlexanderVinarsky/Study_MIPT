#pragma once
#include <iostream>
#pragma once

template <typename T>
class CVector {
class Iterator: public std::forward_iterator_tag
{
private:
    T* current;
public:

    Iterator(T* pos){
        current = pos;
    };
    void * operator++(){
        current=*(current+1);
    };

    bool operator==(Iterator other){
        return current == other.current;
    };
    bool operator!=(Iterator other){
        return current == other.current;
    };

};
private:
    T *data;
    int size;
    int num_elem;

public:
    CVector() {
        data = new T[2];
        size = 2;
        num_elem = 0;
    };
    CVector(int m_size) {
        data = new T[2];
        m_size = m_size;
        num_elem = 0;
    };

    void append(T input) {
        if (size>num_elem) {
            data[num_elem] = input;
        }
        else {
                T* new_data = new T(num_elem * 2);
                for (int i=0; i<num_elem; i++) {
                    new_data[i]=data[i];
                }
                delete[] data;
                data = new_data;
                size++;
        }
    };

    void pop(int pos) {
        num_elem--;
        return data[pos];
        }

    void sort() {
        int left = 0; int right = num_elem-1;
        int i = left, j = right;
        int pivot = data[(left + right) / 2];

        while (i <= j) {
            while (data[i] < pivot)
                i++;
            while (data[j] > pivot)
                j--;
            if (i <= j) {
                std::swap(data[i], data[j]);
                i++;
                j--;
            }
        }

        if (left < j)
            quicksort(data, left, j);
        if (i < right)
            quicksort(data, i, right);
    }

};
