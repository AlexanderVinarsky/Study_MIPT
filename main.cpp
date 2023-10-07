#include <iostream>
#include <cmath>

class Shape {
public:
    virtual double area()=0;
    virtual std::string name()=0;
};

class Triangle : public Shape {
private:
    double a;
    double b;
    double c;
public:
    double area() {
        double p = (a+b+c)/2;
        return p*(p-a)*(p-b)*(p-c);
    };
    std::string name() {return "Triangle";}
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {};
};

class Rectangle : public Shape {
private:
    double a;
    double b;
public:
    double area() {
        return a*b;
    };
    std::string name() {return "Rectangle";}
    Rectangle(double sideA, double sideB) : a(sideA), b(sideB) {};
};

class Circle : public Shape {
private:
    double r;
public:
    double area() {
        return (3.1415926535*pow(r,2));
    };
    std::string name() {return "Circle";}
    Circle(double radius) : r(radius) {};
};

std::ostream & operator<<(std::ostream &stream, Shape * s){
    stream << s->name();
    return stream;
}

int main(){
    Shape *data[3];
    data[0] = new Triangle(3, 4, 5);
    data[1] = new Rectangle(6 ,8);
    data[2] = new Circle(5);

    for(int i = 0; i < 3; ++i){
        std::cout << data[i] << std::endl;
    }
    double s = 0;
    for(int i = 0; i < 3; ++i){
        s += data[i]->area();
    }
    std::cout << "summ area is " << s << std::endl;
    return 0;
}
