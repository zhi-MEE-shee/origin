#include "RightTriangle.h"


	string RightTriangle::getName() { return "������ �����������"; }

	/*bool RightTriangle::check() {
		if (Triangle::check() == false || C != 90) { return false; }
		else return true;
	}*/
	RightTriangle::RightTriangle(): Triangle(40, 20, 60, 30, 50, 90) {
		
		if (A + B + C != 180) {
			throw domain_error("����� ����� �� ����� 180");
		}
		else if (C != 90) {
			throw domain_error("���� � �� ����� 90");
		}
		
		name = getName();
		RightTriangle::print_info();
	};
