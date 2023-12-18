#pragma once
#include "Shape.cpp"

class Circle : public Shape {
private:
    double r;

public:
    double area();
    std::string name();
};