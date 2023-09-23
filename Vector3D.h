#pragma once
//#include "LinkedList.h"

class Vector3D {
private:
    double body[3];

public:
    Vector3D();
    Vector3D(double a1, double a2, double a3);
    Vector3D operator*(Vector3D other);
    Vector3D operator+(Vector3D other);
    Vector3D operator/(Vector3D other);
    Vector3D operator-(Vector3D other);
    double abs();
    void print();
    //LinkedList toList();

    void setCoord(int pos, double a) {
        body[pos] = a;
    }

    int getCoord(int pos) {
        return body[pos];
    }

    friend Vector3D operator+(double first, Vector3D second);
    friend Vector3D operator*(double first, Vector3D second);
    friend Vector3D operator-(double first, Vector3D second);
    friend Vector3D operator/(double first, Vector3D second);

    Vector3D operator+(double first);
    Vector3D operator*(double first);
    Vector3D operator-(double first);
    Vector3D operator/(double first);
};

Vector3D operator+(double first, Vector3D second);
Vector3D operator*(double first, Vector3D second);
Vector3D operator-(double first, Vector3D second);
Vector3D operator/(double first, Vector3D second);
