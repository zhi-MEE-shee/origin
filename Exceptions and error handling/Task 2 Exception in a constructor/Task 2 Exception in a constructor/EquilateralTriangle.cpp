#include "EquilateralTriangle.h"


	string EquilateralTriangle::getName() { return "�������������� �����������"; }

	//bool check() override {
	//	if (Triangle::check() == false || (A != C && A != B && a != c && a != b)) { return false; }
	//	else return true;
	//}


	EquilateralTriangle::EquilateralTriangle() :Triangle(30, 30, 30, 60, 60, 60) {
		if (A + B + C != 180) {
			throw domain_error("����� ����� �� ����� 180");
		}
		else if (A != C && A != B && a != c && a != b) {    //��� ��� ������ �������� ������������� �������� � ������, � �����
			throw domain_error("������� �� �����");
		}

		name = getName();
		EquilateralTriangle::print_info();
	};
