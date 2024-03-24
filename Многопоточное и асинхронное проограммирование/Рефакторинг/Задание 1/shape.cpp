#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include "shape.h"


void Shape::shift(const Point2D& delta) {}; 
void Shape::shift(const Point3D& delta) {}; 
void Shape::scaleZ(int z) {};

Line::Line(const Point2D& p1, const Point2D& p2)
    : p1(p1), p2(p2) {
    type = ShapeType::_2D;
}

double Line::getArea() const {
    return 0;
}

double Line::getVolume() const {
    return 0;
}

ShapeType Line::getType() const { return type; }

 void Line::shift(const Point2D& rhs) {
    p1.x += rhs.x; p1.y += rhs.y;
    p2.x += rhs.x; p2.y += rhs.y;
};

void Line::scale(const int& divider) {
    p1.x /= divider; p1.y /= divider;
    p2.x /= divider; p2.y /= divider;
};

void Line::scaleX(int x) {
    p1.x *= x;
    p2.x *= x;
};
void Line::scaleY(int y) {
    p1.y *= y;
    p2.y *= y;
};



Square::Square(const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4)
    : p1(p1), p2(p2), p3(p3), p4(p4) {
    type = ShapeType::_2D;
}

double Square::getArea() const {
    int side = std::abs(p1.x - p2.x);
    return side * side;
}

double Square::getVolume() const {
    return 0;
}

ShapeType Square::getType() const { return type; }

void Square::shift(const Point2D& rhs) {
    p1.x += rhs.x; p1.y += rhs.y;
    p2.x += rhs.x; p2.y += rhs.y;
    p3.x += rhs.x; p3.y += rhs.y;
    p4.x += rhs.x; p4.y += rhs.y;
};


void Square::scale(const int& divider) {
    p1.x /= divider; p1.y /= divider;
    p2.x /= divider; p2.y /= divider;
    p3.x /= divider; p3.y /= divider;
    p4.x /= divider; p4.y /= divider;
};

void Square::scaleX(int x) {
    p1.x *= x;
    p2.x *= x;
    p3.x *= x;
    p4.x *= x;
};
void Square::scaleY(int y) {
    p1.y *= y;
    p2.y *= y;
    p3.y *= y;
    p4.y *= y;
};



Cube::Cube(const Point3D& p1, const Point3D& p2, const Point3D& p3, const Point3D& p4,
    const Point3D& p5, const Point3D& p6, const Point3D& p7, const Point3D& p8)
    : p1(p1), p2(p2), p3(p3), p4(p4), p5(p5), p6(p6), p7(p7), p8(p8)
{
    type = ShapeType::_3D;
    updateSides();
}

double Cube::getArea() const {
    return 2 * (a * b + a * c + b * c);
}

double Cube::getVolume() const {
    return a * b * c;
}

ShapeType Cube::getType() const { return type; }

void Cube::shift(const Point3D& rhs) {
    p1.x += rhs.x; p1.y += rhs.y;
    p2.x += rhs.x; p2.y += rhs.y;
    p3.x += rhs.x; p3.y += rhs.y;
    p4.x += rhs.x; p4.y += rhs.y;
    p5.x += rhs.x; p5.y += rhs.y;
    p6.x += rhs.x; p6.y += rhs.y;
    p7.x += rhs.x; p7.y += rhs.y;
    p8.x += rhs.x; p8.y += rhs.y;
};


void Cube::scale(const int& divider) {
    p1.x /= divider; p1.y /= divider;
    p2.x /= divider; p2.y /= divider;
    p3.x /= divider; p3.y /= divider;
    p4.x /= divider; p4.y /= divider;
    p5.x /= divider; p5.y /= divider;
    p6.x /= divider; p6.y /= divider;
    p7.x /= divider; p7.y /= divider;
    p8.x /= divider; p8.y /= divider;
};

void Cube::scaleX(int x) {
    p1.x *= x;
    p2.x *= x;
    p3.x *= x;
    p4.x *= x;
    p5.x *= x;
    p6.x *= x;
    p7.x *= x;
    p8.x *= x;

    updateSides();
};
void Cube::scaleY(int y) {
    p1.y *= y;
    p2.y *= y;
    p3.y *= y;
    p4.y *= y;
    p5.y *= y;
    p6.y *= y;
    p7.y *= y;
    p8.y *= y;

    updateSides();
};
void Cube::scaleZ(int z) {
    p1.z *= z;
    p2.z *= z;
    p3.z *= z;
    p4.z *= z;
    p5.z *= z;
    p6.z *= z;
    p7.z *= z;
    p8.z *= z;

    updateSides();
};

void Cube::updateSides() {
    a = std::abs(p1.x - p2.x);
    b = std::abs(p1.y - p3.y);
    c = std::abs(p1.z - p5.z);
};

Circle::Circle(const Point2D& center, double radius)
    : center(center), radius(radius) {
    type = ShapeType::_2D;
}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getVolume() const {
    return 0;
}

ShapeType Circle::getType() const { return type; }

void Circle::shift(const Point2D& rhs) {};
void Circle::scale(const int& divider) {};
void Circle::scaleX(int x) {};
void Circle::scaleY(int y) {};


Cylinder::Cylinder(const Point2D& center, double radius, double height)
    : center(center), radius(radius), height(height) {
    type = ShapeType::_3D;
}

double Cylinder::getArea() const {
    return M_PI * radius * radius + 2 * M_PI * radius * height;
}

double Cylinder::getVolume() const {
    return M_PI * radius * radius * height;
}

ShapeType Cylinder::getType() const { return type; }

void Cylinder::shift(const Point3D& rhs) {};
void Cylinder::scale(const int& divider) {};
void Cylinder::scaleX(int x) {};
void Cylinder::scaleY(int y) {};
void Cylinder::scaleZ(int z) {};