#include "complex.h"

double& Complex::re() {
    return a;
}
double& Complex::im() {
    return b;
}

Complex::Complex(double a, double b) {
    this->a = a;
    this->b = b;
};

Complex Complex::operator+(Complex other) {
    return Complex(a+other.a, b+other.b);
}

Complex operator*(double first, Complex second) {
    return Complex(first*second.a, first*second.b);
}