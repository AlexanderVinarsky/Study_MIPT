//
// Created by vinar on 09.12.2023.
//
#include "Rectangle.h"
#include <string>

double Rectangle::area() {
    return a*b;
}

std::string Rectangle::name() {
    return "Rectangle";
}

Rectangle::Rectangle(double sideA, double sideB) : a(sideA), b(sideB) {};
