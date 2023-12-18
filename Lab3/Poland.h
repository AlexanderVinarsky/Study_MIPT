#pragma once

#include <sstream>
#include "LinkedList.h" // Подключаем заголовочный файл со структурой LinkedList

// Функция для вычисления выражения в обратной польской записи
double calculatePoland(const std::string& expression) {
    LinkedList stack; // Создаем экземпляр структуры LinkedList
    std::istringstream iss(expression); // Создаем поток для разбора выражения
    std::string token;

    while (iss >> token) {
        try {
            if (token == "+") {
                double b = stack.pop(); // Извлекаем два числа из стека
                double a = stack.pop();
                stack.push(a + b); // Выполняем операцию и кладем результат обратно в стек
            } else if (token == "-") {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a - b);
            } else if (token == "*") {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a * b);
            } else if (token == "/") {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(a / b);
            } else {
                stack.push(std::stod(token)); // Если не оператор - преобразуем в число и кладем в стек
            }
        } catch (std::exception& e) {
            std::cerr << "Error in calculatePoland(): " << e.what() << std::endl;
        }
    }

    return stack.pop(); // Возвращаем результат вычислений, который остался в стеке
}