#include "RightTriangle.h"


	std::string RightTriangle::getName() { return "Прямой треугольник"; }

	RightTriangle::RightTriangle() : Triangle(40, 20, 60, 30, 60) {
		name = getName();
	};
