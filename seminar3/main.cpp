#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

template<typename T>
class GeometricForm {
public:
    GeometricForm() = default;

    T calculateArea();

    void printDescription();
};

template<typename T>
class Circle : public GeometricForm<T> {
private:
    T radius;

public:
    Circle(T radius) {
        if (radius < 0)
            throw invalid_argument("Invalid radius");
        this->radius = radius;
    }

    void printDescription() {
        cout << "Circle of radius " << to_string(radius);
    }

    T calculateArea() {
        return numbers::pi * radius * radius;
    }

};

template<typename T>
class Square : public GeometricForm<T> {
private:
    T len;

public:
    Square(T len) {
        if (len < 0)
            throw invalid_argument("Invalid length");
        this->len = len;
    }

    void printDescription() {
        cout << "Square of length " << to_string(len);
    }

    T calculateArea() {
        return len * len;
    }
};

int main() {
    Circle<float> c(2);
    c.printDescription();
    cout << endl << c.calculateArea();
}
