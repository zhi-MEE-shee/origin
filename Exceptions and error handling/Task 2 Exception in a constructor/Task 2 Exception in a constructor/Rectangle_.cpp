#include "Rectangle_.h"


	string Rectangle_::getName()  { return "�������������"; }

	/*bool Rectangle_::check() {
		if (Quadrangle::check() == false || (a != c && b != d && A != 90 && A != B && B != C && C != D)) { return false; }
		else return true;
	}*/

	Rectangle_::Rectangle_() :Quadrangle(55, 85, 55, 85, 90, 90, 90, 90) {

		if (A + B + C + D != 360) {
			throw domain_error("����� ����� �� ����� 360");
		}
		else if (A != 90 && A != B && B != C && C != D && a != c && b != d) {
			throw domain_error("�������������� ������� �� ����� ��� ���� �� ����� 90");
		}
		name = getName();
		Rectangle_::print_info();
	};
