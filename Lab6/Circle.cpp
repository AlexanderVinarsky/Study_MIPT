// Created by vinar on 09.12.2023.
#include "Circle.h"
#include <cmath>
#include <string>

double Circle::area() {
    return (3.1415926535 * pow(r, 2));
}

std::string Circle::name() {
    return "Circle";
}