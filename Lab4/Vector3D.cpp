#include <cmath>
#include <iostream>
#include "Vector3D.h"
#include <stdexcept>

Vector3D::Vector3D() {
    try {
        for (int i = 0; i<3; i++) {
            this->body[i] = 0;
        }
    } catch (std::exception& e) {
        std::cerr << "Error in Vector3D() constructor: " << e.what() << std::endl;
    }
}

Vector3D::Vector3D(double a1, double a2, double a3) {
    try {
        this->body[0] = a1;
        this->body[1] = a2;
        this->body[2] = a3;
    } catch (std::exception& e) {
        std::cerr << "Error in Vector3D(double, double, double) constructor: " << e.what() << std::endl;
    }
}

Vector3D Vector3D::operator*(Vector3D other) {
    try {
        return Vector3D(body[0]*other.body[0], body[1]*other.body[1], body[2]*other.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator*(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D Vector3D::operator+(Vector3D other) {
    try {
        return Vector3D(body[0]+other.body[0], body[1]+other.body[1], body[2]+other.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator+(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D Vector3D::operator-(Vector3D other) {
    try {
        return Vector3D(body[0]-other.body[0], body[1]-other.body[1], body[2]-other.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator-(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D Vector3D::operator/(Vector3D other) {
    try {
        return Vector3D(body[0]/other.body[0], body[1]/other.body[1], body[2]/other.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator/(): " << e.what() << std::endl;
        return Vector3D();
    }
};

double Vector3D::abs() {
    return sqrt(pow((body[0]),2) + pow((body[1]),2) + pow((body[2]),2));
};

void Vector3D::print() {
    try {
        for (int i = 0; i < 3; i++) {
            std::cout << body[i] << " ";
        }
    } catch (std::exception& e) {
        std::cerr << "Error in print(): " << e.what() << std::endl;
    }
};

Vector3D operator*(double first, Vector3D second) {
    try {
        return Vector3D(first*second.body[0], first*second.body[1], first*second.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator*(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D operator/(double first, Vector3D second) {
    try {
        return Vector3D(first/second.body[0], first/second.body[1], first/second.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator/(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D operator+(double first, Vector3D second) {
    try {
        return Vector3D(first+second.body[0], first+second.body[1], first+second.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator+(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D operator-(double first, Vector3D second) {
    try {
        return Vector3D(first-second.body[0], first-second.body[1], first-second.body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator-(): " << e.what() << std::endl;
        return Vector3D();
    }
};

Vector3D Vector3D::operator+(double first) {
    try {
        return Vector3D(first+body[0], first+body[1], first+body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator+(): " << e.what() << std::endl;
        return Vector3D();
    }
};
Vector3D Vector3D::operator*(double first) {
    try {
        return Vector3D(first*body[0], first*body[1], first*body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator*(): " << e.what() << std::endl;
        return Vector3D();
    }
};
Vector3D Vector3D::operator-(double first) {
    try {
        return Vector3D(first-body[0], first-body[1], first-body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator-(): " << e.what() << std::endl;
        return Vector3D();
    }
};
Vector3D Vector3D::operator/(double first) {
    try {
        return Vector3D(first/body[0], first/body[1], first/body[2]);
    } catch (std::exception& e) {
        std::cerr << "Error in operator/(): " << e.what() << std::endl;
        return Vector3D();
    }
};

