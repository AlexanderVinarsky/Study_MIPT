#pragma once
#include "Shape.cpp"

class Triangle : public Shape {
private: // Приватные переменные (стороны)
    double a;
    double b;
    double c;
public:
    double area(); // Площадь
    std::string name(); //Название фигуры
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {}; //Конструктор
};