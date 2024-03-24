#pragma once
#include "shape.h"
#include <typeinfo>

class transform {
public:
    virtual void apply(Shape& shape) const = 0;
};



template <typename T>
class Shift : public transform {
public:
    Shift(T& point) : point(point) {}

    void apply(Shape& shape) const override {
        shape.shift(point);
    }

private:
    mutable T point;
};



//деление
class Scale : public transform {
public:
    Scale(const int& divider);

    void apply(Shape& shape) const override;

private:
    int divider;
};


//смещение по X, Y, Z
class ScaleX : public transform {
public:
    ScaleX(int x);

    void apply(Shape& shape) const override;

private:
    int x;
};

class ScaleY : public transform {
public:
    ScaleY(int y);

    void apply(Shape& shape) const override;

private:
    int y;
};

class ScaleZ : public transform {
public:
    ScaleZ(int z);

    void apply(Shape& shape) const override;

private:
    int z;
};

