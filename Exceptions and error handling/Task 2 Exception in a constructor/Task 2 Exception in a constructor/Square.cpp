#include "Square.h"


	string Square::getName() { return "�������"; }
	/*bool Square::check()  {
		if (Quadrangle::check() == false || (a != c && b != d && a != b && A != 90 && A != B && B != C && C != D)) { return false; }
		else return true;
	}*/

	Square::Square() : Quadrangle(40, 40, 40, 40, 90, 90, 90, 90) {

		if (A + B + C + D != 360) {
			throw domain_error("����� ����� �� ����� 360");
		}
		else if (a != c && b != d && a != b && A != 90 && A != B && B != C && C != D) {
			throw domain_error("������� �� �����");
		}

		name = getName();
		Square::print_info();
	}
