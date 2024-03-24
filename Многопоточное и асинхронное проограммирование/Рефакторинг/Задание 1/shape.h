#pragma once

enum class ShapeType {
 /*   Line,
    Square,
    Cube,
    Circle,
    Cylinder*/
    _2D,
    _3D

};


//struct Point2D {
//    int x, y;
//};
//
//struct Point3D {
//    int x, y, z;
//};

struct Point {
    int x, y, z;
};

struct Point2D : public Point {
    Point2D(int x, int y) : Point{ x, y, 0 } {}
};

struct Point3D : public Point {
    Point3D(int x, int y, int z) : Point{ x, y, z } {}
};



class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
    virtual ShapeType getType() const = 0;
    virtual void shift(const Point2D& delta); 
    virtual void shift(const Point3D& delta); 
    virtual void scale(const int& divider) = 0;
    virtual void scaleX(int x) = 0;
    virtual void scaleY(int y) = 0;
    virtual void scaleZ(int z);
};


class Shape2D : public Shape {
public:
    virtual void shift(const Point2D& delta) override = 0;
    virtual void scaleX(int x) override = 0;
    virtual void scaleY(int y) override = 0;
};

class Shape3D : public Shape {
public:
    virtual void shift(const Point3D& delta) override = 0;
    virtual void scaleX(int x) override = 0;
    virtual void scaleY(int y) override = 0;
    virtual void scaleZ(int Z) override = 0;
};


class Line : public Shape2D {
public:
    Line(const Point2D& p1, const Point2D& p2);

    double getArea() const override;
    double getVolume() const override;
    ShapeType getType() const override;
private:
    void shift(const Point2D& rhs) override;
    void scale(const int& divider) override;
    void scaleX(int x) override;
    void scaleY(int y) override;

    Point2D p1, p2;
    ShapeType type;
};


class Square : public Shape2D {
public:
    Square(const Point2D& p1, const Point2D& p2, const Point2D& p3, const Point2D& p4);

    double getArea() const override;
    double getVolume() const override;
    ShapeType getType() const override;
private:
    void shift(const Point2D& rhs) override;
    void scale(const int& divider) override;
    void scaleX(int x) override;
    void scaleY(int y) override;
 
    Point2D p1, p2, p3, p4;
    ShapeType type;
};


class Cube : public Shape3D {
public:
    Cube(const Point3D& p1, const Point3D& p2, const Point3D& p3, const Point3D& p4,
         const Point3D& p5, const Point3D& p6, const Point3D& p7, const Point3D& p8);

    double getArea() const override;
    double getVolume() const override;
    ShapeType getType() const override;
private:
    void shift(const Point3D& rhs) override;
    void scale(const int& divider) override;
    void scaleX(int x) override;
    void scaleY(int y) override;
    void scaleZ(int z) override;
    void updateSides();

    double a, b, c;
    Point3D p1, p2, p3, p4, p5, p6, p7, p8;
    ShapeType type;
};


class Circle : public Shape2D {
public:
    Circle(const Point2D& center, double radius);

    double getArea() const override;
    double getVolume() const override;
    ShapeType getType() const override;
private:
    void shift(const Point2D& rhs) override;
    void scale(const int& divider) override;
    void scaleX(int x) override;
    void scaleY(int y) override;

    Point2D center;
    double radius;
    ShapeType type;
};


class Cylinder : public Shape3D {
public:
    Cylinder(const Point2D& center, double radius, double height);

    double getArea() const override;
    double getVolume() const override;
    ShapeType getType() const override;
private:
    void shift(const Point3D& rhs) override;
    void scale(const int& divider) override;
    void scaleX(int x) override;
    void scaleY(int y) override;
    void scaleZ(int z) override;


    Point2D center;
    double radius, height;
    ShapeType type;
};













