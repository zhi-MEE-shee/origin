#include "IsoscelesTriangle.h"


	string IsoscelesTriangle::getName() { return "Равнобедренный треугольник"; }

	//bool  IsoscelesTriangle::check() {
	//	if (Triangle::check() == false || (A != C && a != c)) { return false; }
	//	else return true;
	//}

	IsoscelesTriangle::IsoscelesTriangle() : Triangle(30, 40, 20, 55, 50, 75) {
		if (A + B + C != 180) {
			throw domain_error("сумма углов не равна 180");
		}
		if (A != C && a != c) {
			throw domain_error("две стороны не равны между собой");
		}
		name = getName();
		IsoscelesTriangle::print_info();
	};
