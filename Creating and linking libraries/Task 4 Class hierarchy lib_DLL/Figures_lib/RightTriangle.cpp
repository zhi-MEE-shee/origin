#include "RightTriangle.h"


	std::string Figures::RightTriangle::getName() { return "Прямой треугольник"; }

	Figures::RightTriangle::RightTriangle() : Triangle(40, 20, 60, 30, 60) {
		name = getName();
	};
