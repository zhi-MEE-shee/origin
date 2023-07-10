#include "EquilateralTriangle.h"


	string EquilateralTriangle::getName() { return "Равносторонний треугольник"; }

	//bool check() override {
	//	if (Triangle::check() == false || (A != C && A != B && a != c && a != b)) { return false; }
	//	else return true;
	//}


	EquilateralTriangle::EquilateralTriangle() :Triangle(30, 30, 30, 60, 60, 60) {
		if (A + B + C != 180) {
			throw domain_error("сумма углов не равна 180");
		}
		else if (A != C && A != B && a != c && a != b) {    //все еще нахожу странной необходимость проверки и сторон, и углов
			throw domain_error("стороны не равны");
		}

		name = getName();
		EquilateralTriangle::print_info();
	};
