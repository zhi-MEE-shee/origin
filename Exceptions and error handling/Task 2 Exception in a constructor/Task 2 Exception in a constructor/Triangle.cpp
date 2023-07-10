#include "Triangle.h"

	string Triangle::getName() { return "Треугольник"; }

	/*bool Triangle::check() {
		return A + B + C != 180 ? true : false;
	}*/

	//конструктор произвольного треугольника
	Triangle::Triangle(int a, int b, int c, int A, int B, int C) {

		if (A + B + C != 180) {
			throw domain_error("сумма углов не равна 180");
		}

		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;

		name = getName();
		quantOfSides = 3;
	}


	Triangle::Triangle() : Triangle(10, 20, 30, 35, 100, 45) {	

		Triangle::print_info();
	};

	int Triangle::getSide_a() { return a; }
	int Triangle::getSide_b() { return b; }
	int Triangle::getSide_c() { return c; }

	int Triangle::getAngle_A() { return A; }
	int Triangle::getAngle_B() { return B; }
	int Triangle::getAngle_C() { return C; }


	void Triangle::print_info() {

		Figure::print_info();
		cout << name << "(cтороны: " << getSide_a() << ", " << getSide_b() << ", " << getSide_c() << "; " << endl
			<< "углы: " << getAngle_A() << ", " << getAngle_B() << ", " << getAngle_C() << ") создан" << endl << endl;
	}
