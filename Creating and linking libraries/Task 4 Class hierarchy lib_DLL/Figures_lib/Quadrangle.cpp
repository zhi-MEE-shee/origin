#include "Quadrangle.h"

	std::string Figures::Quadrangle::getName() { return "Четырёхугольник"; }

	//конструктор четырехугольника
	Figures::Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
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
	Figures::Quadrangle::Quadrangle(int a, int c, int A, int C) {
		this->a = a;
		b = a;
		this->c = c;
		d = c;
		this->A = A;
		B = A;
		this->C = C;
		D = C;
	}

	Figures::Quadrangle::Quadrangle() : Quadrangle(20, 10, 30, 40, 30, 35, 160, 80) {
		name = getName();
	};

	int Figures::Quadrangle::getSide_a() { return a; }
	int Figures::Quadrangle::getSide_b() { return b; }
	int Figures::Quadrangle::getSide_c() { return c; }
	int Figures::Quadrangle::getSide_d() { return d; }
	int Figures::Quadrangle::getAngle_A() { return A; }
	int Figures::Quadrangle::getAngle_B() { return B; }
	int Figures::Quadrangle::getAngle_C() { return C; }
	int Figures::Quadrangle::getAngle_D() { return D; }

	void Figures::Quadrangle::print() {
		std::cout << name << ": " << std::endl
			<< "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << ", d = " << getSide_d() << std::endl
			<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << ", D = " << getAngle_D() << std::endl << std::endl;
	}
