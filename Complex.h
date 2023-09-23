#pragma once

#include <iosfwd>

class Complex {
private:
    double a, b;
public:
    double& re();
    double& im();
    Complex(double re, double im=0.0);

    Complex operator+(Complex other);
    friend Complex operator* (double first, Complex second);
};

Complex operator* (double first, Complex second);
std::ostream& operator<<(std::ostream& stream, Complex z);