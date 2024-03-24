#include <iostream>
#include "shape.h" 
#include "transform.h"

int main() {
    
   Line line({ 0, 0 }, { 10, 10 });
    Square square({ 0, 0 }, { 10, 0 }, { 0, 10 }, { 10, 10 });
    Cube cube({ 0, 0, 0 },  { 10, 0, 0 }, { 0, 10, 0 }, { 10, 10, 0 },
              { 0, 0, 10 }, { 10, 0, 10 }, { 0, 10, 10 }, { 10, 10, 10 });
    Circle circle({ 0, 0 }, 5);
    Cylinder cylinder({ 0, 0 }, 5, 10);

    std::cout << "Line: area = " << line.getArea() << ", volume = " << line.getVolume() << '\n';
    std::cout << "Square: area = " << square.getArea() << ", volume = " << square.getVolume() << '\n';
    std::cout << "Cube: area = " << cube.getArea() << ", volume = " << cube.getVolume() << '\n';
    std::cout << "Circle: area = " << circle.getArea() << ", volume = " << circle.getVolume() << '\n';
    std::cout << "Cylinder: area = " << cylinder.getArea() << ", volume = " << cylinder.getVolume() << '\n';


    Point2D shiftX3{ 3, 3 };
    Shift<Point2D> squareShift(shiftX3);
    squareShift.apply(square);
    std::cout << "Square: area = " << square.getArea() << ", volume = " << square.getVolume() << '\n';

    try {
        Scale scl(0);
        scl.apply(square);
        std::cout << "Square: area = " << square.getArea() << ", volume = " << square.getVolume() << '\n';
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    
    
    ScaleX sclX(3);
    sclX.apply(square);
    std::cout << "Square: area = " << square.getArea() << ", volume = " << square.getVolume() << '\n';


    ScaleX scaleX(2);
    ScaleY scaleY(2);
    ScaleZ scaleZ(2);

    scaleX.apply(cube);
    scaleY.apply(cube);
    scaleZ.apply(cube);
    std::cout << "Cube: area = " << cube.getArea() << ", volume = " << cube.getVolume() << '\n';

    return 0;
}