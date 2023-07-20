#include "Triangle.h"

	std::string Figures::Triangle::getName() { return "Треугольник"; }

	//конструктор произвольного треугольника
	Figures::Triangle::Triangle(int a, int b, int c, int A, int B, int C) {

		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = getName();
	}

	//конструктор прямоуголного треугольника
	Figures::Triangle::Triangle(int a, int b, int c, int A, int B) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;

		C = 90;
	}
	//конструктор равнобедренного треугольника
	Figures::Triangle::Triangle(int a, int c, int A, int C) {
		this->a = a;
		b = a;
		this->c = c;
		this->A = A;
		B = A;
		this->C = C;
	}

	//конструктор равностороннего треугольника
	Figures::Triangle::Triangle(int a, int A) {
		this->a = a;
		b = a;
		c = a;
		this->A = A;
		B = A;
		C = A;
	}

	Figures::Triangle::Triangle() : Triangle(10, 20, 30, 35, 100, 45) {};

	int Figures::Triangle::getSide_a() { return a; }
	int Figures::Triangle::getSide_b() { return b; }
	int Figures::Triangle::getSide_c() { return c; }

	int Figures::Triangle::getAngle_A() { return A; }
	int Figures::Triangle::getAngle_B() { return B; }
	int Figures::Triangle::getAngle_C() { return C; }

	std::string Figures::Triangle::getNameForOutput() { return name; }

	void Figures::Triangle::print() {
		std::cout << name << ": " << std::endl
			<< "Стороны: a = " << getSide_a() << ", b = " << getSide_b() << ", c = " << getSide_c() << std::endl
			<< "Углы: A = " << getAngle_A() << ", B = " << getAngle_B() << ", C = " << getAngle_C() << std::endl << std::endl;
	}
