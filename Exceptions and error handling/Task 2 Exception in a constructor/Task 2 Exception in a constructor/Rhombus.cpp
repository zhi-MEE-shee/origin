#include "Rhombus.h"


	string Rhombus::getName() { return "Ромб"; }

	/*bool Rhombus::check()  {
		if (Quadrangle::check() == false || (a != c && b != d && a != b && A != C && B != D)) { return false; }
		else return true;
	}*/


	Rhombus::Rhombus() : Quadrangle(40, 50, 45, 40, 80, 100, 90, 90) {
		if (A + B + C + D != 360) {
			throw domain_error("сумма углов не равна 360");
		}
		else if (a != c && b != d && a != b && A != C && B != D) {
			throw domain_error("стороны не равны или противолежащие углы не равны");
		}

		name = getName();
		Rhombus::print_info();
	};

