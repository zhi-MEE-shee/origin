#include "EquilateralTriangle.h"


	std::string EquilateralTriangle::getName() { return "Равносторонний треугольник"; }

	EquilateralTriangle::EquilateralTriangle() :Triangle(30, 60) {
		name = getName();
	};


