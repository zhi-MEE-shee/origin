#include "Quadrangle.h"


	string Quadrangle::getName() { return "Четырёхугольник"; }

	/*bool Quadrangle::check() {
		return A + B + C + D == 360 ? true : false;
	}*/

	//конструктор четфрехугольника
	Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {

		if (A + B + C + D != 360) {
			throw domain_error("сумма углов не равна 360");
		}

		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;

		quantOfSides = 4;
		name = getName();
	}


	Quadrangle::Quadrangle() : Quadrangle(20, 10, 30, 40, 30, 35, 160, 80) {

		Quadrangle::print_info();
	};

	int Quadrangle::getSide_a() { return a; }
	int Quadrangle::getSide_b() { return b; }
	int Quadrangle::getSide_c() { return c; }
	int Quadrangle::getSide_d() { return d; }
	int Quadrangle::getAngle_A() { return A; }
	int Quadrangle::getAngle_B() { return B; }
	int Quadrangle::getAngle_C() { return C; }
	int Quadrangle::getAngle_D() { return D; }

	void Quadrangle::print_info() {

		cout << name << "(cтороны: " << getSide_a() << ", " << getSide_b() << ", " << getSide_c() << ", " << getSide_d() << "; " << endl
			<< "углы: " << getAngle_A() << ", " << getAngle_B() << ", " << getAngle_C() << ", " << getAngle_D() << ") создан" << endl << endl;
	}
