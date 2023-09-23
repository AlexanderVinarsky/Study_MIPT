#include <cmath>
#include <iostream>
#include "Vector3D.h"

Vector3D::Vector3D() {
    for (int i = 0; i<3; i++) {
        this->body[i] = 0;
    }
};

Vector3D::Vector3D(double a1, double a2, double a3) {
    this->body[0] = a1;
    this->body[1] = a2;
    this->body[2] = a3;
};

Vector3D Vector3D::operator*(Vector3D other) {
    return Vector3D(body[0]*other.body[0], body[1]*other.body[1], body[2]*other.body[2]);
};

Vector3D Vector3D::operator+(Vector3D other) {
    return Vector3D(body[0]+other.body[0], body[1]+other.body[1], body[2]+other.body[2]);
};

Vector3D Vector3D::operator-(Vector3D other) {
    return Vector3D(body[0]-other.body[0], body[1]-other.body[1], body[2]-other.body[2]);
};

Vector3D Vector3D::operator/(Vector3D other) {
    return Vector3D(body[0]/other.body[0], body[1]/other.body[1], body[2]/other.body[2]);
};

double Vector3D::abs() {
    return sqrt(pow((body[0]),2) + pow((body[1]),2) + pow((body[2]),2));
};

void Vector3D::print() {
    for (int i = 0; i < 3; i++) {
        std::cout << body[i] << " ";
    }
}

//LinkedList Vector3D::toList() {
//    LinkedList list = *new LinkedList;
//    for (int i = 0; i<3; i++) {
//        list.push(body[i]);
//    }
//    return list;
//}

Vector3D operator*(double first, Vector3D second) {
    return Vector3D(first*second.body[0], first*second.body[1], first*second.body[2]);
};

Vector3D operator/(double first, Vector3D second) {
    return Vector3D(first/second.body[0], first/second.body[1], first/second.body[2]);
};

Vector3D operator+(double first, Vector3D second) {
    return Vector3D(first+second.body[0], first+second.body[1], first+second.body[2]);
};

Vector3D operator-(double first, Vector3D second) {
    return Vector3D(first-second.body[0], first-second.body[1], first-second.body[2]);
}

Vector3D Vector3D::operator+(double first) {
    return Vector3D(first+body[0], first+body[1], first+body[2]);
};
Vector3D Vector3D::operator*(double first) {
    return Vector3D(first*body[0], first*body[1], first*body[2]);
};
Vector3D Vector3D::operator-(double first) {
    return Vector3D(first-body[0], first-body[1], first-body[2]);
};
Vector3D Vector3D::operator/(double first) {
    return Vector3D(first/body[0], first/body[1], first/body[2]);
};

