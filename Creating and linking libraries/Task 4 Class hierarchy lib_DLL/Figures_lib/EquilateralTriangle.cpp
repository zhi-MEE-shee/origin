#include "EquilateralTriangle.h"


std::string Figures::EquilateralTriangle::getName() { return "�������������� �����������"; }

Figures::EquilateralTriangle::EquilateralTriangle() :Triangle(30, 60) {
	name = getName();
};


