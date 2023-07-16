#include "IsoscelesTriangle.h"


	std::string IsoscelesTriangle::getName() { return "Равнобедренный треугольник"; }

	
	IsoscelesTriangle::IsoscelesTriangle() : Triangle(30, 20, 55, 70) {
		name = getName();
	};

