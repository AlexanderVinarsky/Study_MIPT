#pragma once

#include <string>
#include "Shape.cpp"

class Rectangle : public Shape {
private:
    double a;
    double b;
public:
    double area();
    std::string name();
    Rectangle(double sideA, double sideB);
};