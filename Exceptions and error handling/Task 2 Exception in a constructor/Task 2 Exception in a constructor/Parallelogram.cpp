#include "Parallelogram.h"


	string Parallelogram::getName() { return "��������������"; }

	/*bool Parallelogram::check()  {
		if (Quadrangle::check() == false || (A != C && B != D && a != c && b != d)) { return false; }
		else return true;
	}*/
	Parallelogram::Parallelogram() :Quadrangle(40, 55, 40, 55, 120, 60, 120, 60) {

		if (A + B + C + D != 360) {
			throw domain_error("����� ����� �� ����� 360");
		}
		else if (A != C && B != D && a != c && b != d) {
			throw domain_error("�������������� ������� � ���� �� �����");
		}
		name = getName();
		Parallelogram::print_info();
	};

