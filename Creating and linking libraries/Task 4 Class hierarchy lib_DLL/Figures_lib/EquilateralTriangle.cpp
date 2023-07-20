#include "EquilateralTriangle.h"


std::string Figures::EquilateralTriangle::getName() { return "Равносторонний треугольник"; }

Figures::EquilateralTriangle::EquilateralTriangle() :Triangle(30, 60) {
	name = getName();
};


