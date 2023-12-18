//
// Created by vinar on 09.12.2023.
//

#pragma once
#include <string>

class Shape {
public:
    virtual double area() = 0;
    virtual std::string name() = 0;
};