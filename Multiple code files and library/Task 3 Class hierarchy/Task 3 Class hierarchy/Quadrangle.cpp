#include "Quadrangle.h"

	string Quadrangle::getName() { return "Четырёхугольник"; }

	//конструктор четырехугольника
	Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	//конструктор параллелограмма
	Quadrangle::Quadrangle(int a, int c, int A, int C) {
		this->a = a;
		b = a;
		this->c = c;
		d = c;
		this->A = A;
		B = A;
		this->C = C;
		D = C;
	}

	Quadrangle::Quadrangle() : Quadrangle(20, 10, 30, 40, 30, 35, 160, 80) {
		name = getName();
	};

	int Quadrangle::getSide_a() { return a; }
	int Quadrangle::getSide_b() { return b; }
	int Quadrangle::getSide_c() { return c; }
	int Quadrangle::getSide_d() { return d; }
	int Quadrangle::getAngle_A() { return A; }
	int Quadrangle::getAngle_B() { return B; }
	int Quadrangle::getAngle_C() { return C; }
	int Quadrangle::getAngle_D() { return D; }

	void Quadrangle::print() {
		cout << name << ": " << endl
			<< "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << ", d = " << getSide_d() << endl
			<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << ", D = " << getAngle_D() << endl << endl;
	}
