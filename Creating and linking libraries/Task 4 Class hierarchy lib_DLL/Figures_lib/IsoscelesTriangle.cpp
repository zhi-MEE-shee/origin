#include "IsoscelesTriangle.h"


	std::string Figures::IsoscelesTriangle::getName() { return "Равнобедренный треугольник"; }

	
	Figures::IsoscelesTriangle::IsoscelesTriangle() : Triangle(30, 20, 55, 70) {
		name = getName();
	};

