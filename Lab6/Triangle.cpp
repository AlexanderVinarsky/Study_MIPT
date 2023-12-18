//
// Created by vinar on 09.12.2023.
//
#include "Triangle.h"
#include "Shape.cpp"

double Triangle::area() {
        double p = (a+b+c)/2;
        return p*(p-a)*(p-b)*(p-c);
    };

std::string Triangle::name() {
        return "Triangle";
    };